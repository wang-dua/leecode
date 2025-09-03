#pragma once
#include <unordered_map>
#include <list>

//手动维护 lru的list
class LRUCache {
private:

    /*
     * lru节点
     *有头尾节点的双向链表用于存储节点, 尾插或者头插, 淘汰头或尾
     *map存储key, lrunode
     */
    class LruNode
    {
    public:
        int key;
        int value;
        LruNode* prev;
        LruNode* next;
    public:
        LruNode() = default;
        LruNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };
    std::unordered_map<int, LruNode*>  nodemap;
    int capacity;
    LruNode* head;
    LruNode* tail;

public:
    LRUCache(int capacity) : capacity(capacity) {
        //初始化双向链表
        head = new LruNode();
        tail = new LruNode();
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache()
    {
        LruNode* curnode = head->next;
        while (curnode)
        {
            LruNode* tmp = curnode;
            curnode = curnode->next;
            delete tmp;
        }
        delete head;
    }

    //将一个节点更新到最新, 到头部
    void updateNode(LruNode* node)
    {
        removeNode(node);
        addNode(node);
    }
    void removeNode(LruNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
    }
    void addNode(LruNode* node)
    {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    void popTail()
    {
        if (head->next == tail) return;
        auto node = tail->prev;
        nodemap.erase(node->key);
        removeNode(node);
        delete node;
    }

    int get(int key) {
        auto it = nodemap.find(key);
        if (it == nodemap.end()) return -1;

        updateNode(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = nodemap.find(key);
        if (it != nodemap.end())
        {
            it->second->value = value;
            updateNode(it->second);
            return; //已有的节点更新后直接返回
        }

        LruNode* newNode = new LruNode(key, value);
        nodemap[key] = newNode;
        addNode(newNode);

        if (nodemap.size() > capacity) popTail();

    }
};




template<typename Key, typename Value>
class STLCache {
private:
    int capacity;
    using  pairList = std::list<std::pair<Key, Value>>;
    pairList nodeLi;            //如果要使用list, 就没必要写自定义Node结构体了
    std::unordered_map<Key, typename pairList::iterator> nodeMap;
public:
    STLCache(int capacity): capacity(capacity)
    {
    }
    //由于是list自动维护, 不需要写removeNode addNode 
    void put(const Key& key, const Value& value)
    {
        auto it = nodeMap.find(key);
        if (it != nodeMap.end()) //找到
        {
	       //更新节点将节点移动到头部
            it->second->second = value;
            //将nodeLi(二参)的所指向的位置(三参)的元素 转移到*this的(一参)位置
            nodeLi.splice(nodeLi.begin(), nodeLi, it->second);
            return;
        }

        if (nodeMap.size() >= capacity)
        {
            auto deleteIt = std::prev(nodeLi.end());
            nodeLi.pop_back();
            nodeMap.erase(deleteIt->first);
        }
        nodeLi.emplace_front(key, value);
        nodeMap[key] = nodeLi.begin();

    }

    Value get(const Key& key)
    {
        auto it = nodeMap.find(key);
        if (it != nodeMap.end())
        {
            nodeLi.splice(nodeLi.begin(), nodeLi, it->second);
            return it->second->second;
        }
        return Value{};
    }
};