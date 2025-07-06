# 704二分查找: 
遵循循环不变量原则, 双闭区间, 半开半闭区分清楚

# 59螺旋矩阵: 
**同样遵循循环一致性原则**, 利用 count 变量 填充, 按圈数循环, 同时注意中间值

# 203移除链表元素: 
1. **创建dummyHead 和 无dummyHead 是两种思路**, 前者更明了-返回dummHead_->next_, 后者需要单独设置循环清除head
2. 需要注意对于循环条件的->next使用, 不能对nullptr使用->next

# 707设计链表
1. get(index)	找到第 index 个节点（从 0 开始）
2. addAtIndex(i)	找到 第 i 个节点的前一个节点（插在前面）
3. deleteAtIndex(i)	找到 第 i 个节点的前一个节点（删除第 i 个）

统一遍历: 从dummyHead开始i=0, 到i < index结束, 这样get() 时再走一步：curr = curr->next;

add() 时：curr 就是第 index 个节点的前一个，正好插入

delete() 时：curr 也是第 index 个节点的前一个，正好删除