#pragma once
#include <unordered_map>
#include <list>

//�ֶ�ά�� lru��list
class LRUCache {
private:

    /*
     * lru�ڵ�
     *��ͷβ�ڵ��˫���������ڴ洢�ڵ�, β�����ͷ��, ��̭ͷ��β
     *map�洢key, lrunode
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
        //��ʼ��˫������
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

    //��һ���ڵ���µ�����, ��ͷ��
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
            return; //���еĽڵ���º�ֱ�ӷ���
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
    pairList nodeLi;            //���Ҫʹ��list, ��û��Ҫд�Զ���Node�ṹ����
    std::unordered_map<Key, typename pairList::iterator> nodeMap;
public:
    STLCache(int capacity): capacity(capacity)
    {
    }
    //������list�Զ�ά��, ����ҪдremoveNode addNode 
    void put(const Key& key, const Value& value)
    {
        auto it = nodeMap.find(key);
        if (it != nodeMap.end()) //�ҵ�
        {
	       //���½ڵ㽫�ڵ��ƶ���ͷ��
            it->second->second = value;
            //��nodeLi(����)����ָ���λ��(����)��Ԫ�� ת�Ƶ�*this��(һ��)λ��
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