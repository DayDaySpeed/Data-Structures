#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int key;    // 存nums中的数值
	int idx;    // 存数组下标
	Node* next;
} Node;

class MyHashMap {
private:
	static const int SIZE = 10;
	Node* bucket[SIZE];

public:
	class iterator
	{
	public:
		Node* ptr;

		iterator(Node* p = nullptr)
		{
			ptr = p;
		}

		bool operator!=(const iterator& other) const
		{
			return ptr != other.ptr;
		}

		Node* operator->()
		{
			return ptr;
		}

		Node& operator*()
		{
			return *ptr;
		}

		// 新增前置自增，支持it++遍历
		iterator& operator++()
		{
			if (ptr == nullptr)
				return *this;
			ptr = ptr->next;
			return *this;
		}
	};

	// 构造：初始化每个桶为哨兵循环头结点
	MyHashMap() {
		for (int i = 0; i < SIZE; i++) {
			bucket[i] = new Node();
			bucket[i]->next = bucket[i];
		}
	}

	// 哈希函数
	int hash(int key) {
		return (key % SIZE + SIZE) % SIZE;
	}

	// 插入：key是数值，idx是数组下标
	void insert(int key, int idx) {
		int index = hash(key);
		Node* newNode = new Node{ key, idx, nullptr };
		// 头插法，插在哨兵后面
		newNode->next = bucket[index]->next;
		bucket[index]->next = newNode;
	}

	// 根据key查找节点，返回迭代器
	iterator find(int key)
	{
		int index = hash(key);
		Node* current = bucket[index]->next;
		while (current != bucket[index])
		{
			if (current->key == key)
			{
				return iterator(current);
			}
			current = current->next;
		}
		return end();
	}

	// 尾后迭代器
	iterator end()
	{
		return iterator(nullptr);
	}

	// 打印整个哈希表
	void print() {
		for (int i = 0; i < SIZE; i++) {
			Node* current = bucket[i]->next;
			cout << "Bucket " << i << ": ";
			while (current != bucket[i]) {
				cout << "(key:" << current->key << ", idx:" << current->idx << ") -> ";
				current = current->next;
			}
			cout << "self(sentinel)" << endl;
		}
	}

	// 析构函数，释放所有内存，避免泄漏
	~MyHashMap()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			Node* cur = bucket[i]->next;
			while (cur != bucket[i])
			{
				Node* del = cur;
				cur = cur->next;
				delete del;
			}
			delete bucket[i];
		}
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		MyHashMap hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				// it->idx 是之前元素下标，i是当前下标
				return { it->idx, i };
			}
			// 存入当前数值和下标
			hashtable.insert(nums[i], i);
		}
		return {};
	}
};

int main() {
	MyHashMap map;
	map.insert(1, 10);
	map.insert(11, 15);
	map.insert(21, 25);
	map.insert(2, 20);
	map.insert(12, 30);
	map.insert(22, 40);
	map.print();

	auto it = map.find(12);
	if (it != map.end())
	{
		cout << "\nFound key 12, idx value: " << it->idx << endl;
	}
	else
	{
		cout << "\nKey 12 not found." << endl;
	}

	// 测试两数之和
	vector<int> arr = { 11,15,2,7 };
	Solution sol;
	vector<int> res = sol.twoSum(arr, 9);
	cout << "\ntwoSum result: " << res[0] << " " << res[1] << endl;

	return 0;
}