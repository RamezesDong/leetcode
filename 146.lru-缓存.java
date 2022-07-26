/*
 * @lc app=leetcode.cn id=146 lang=java
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    class Node {
        int key;
        int value;
        Node next;
        Node prev;
        
        Node(int k, int v) {
            key = k;
            value = v;
            next = null;
            prev = null;
        }
    }
    HashMap<Integer, Node> map;
    Node head;
    Node tail; 
    int capacity;
    int size = 0;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (map.containsKey(key)) {
            Node res = map.get(key);
            res.prev.next = res.next;
            res.next.prev = res.prev;
            res.next = head.next;
            head.next = res;
            res.next.prev = res;
            res.prev = head;
            return res.value;
        } else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node res = map.get(key);
            res.prev.next = res.next;
            res.next.prev = res.prev;
            res.next = head.next;
            head.next = res;
            res.next.prev = res;
            res.prev = head;
            res.value = value;
        } else {
            if (size == capacity) {
                Node evict = tail.prev;
                evict.prev.next = evict.next;
                evict.next.prev = evict.prev;
                map.remove(evict.key);
                evict = null;
                Node res = new Node(key, value);
                map.put(key, res);
                res.next = head.next;
                head.next = res;
                res.prev = head;
                res.next.prev = res;
            } else {
                Node res = new Node(key, value);
                map.put(key, res);
                res.next = head.next;
                head.next = res;
                res.prev = head;
                res.next.prev = res;
                size += 1;
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

