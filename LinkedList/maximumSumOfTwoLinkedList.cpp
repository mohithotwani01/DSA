// Asked to Aayushi in Final Round of Amazon

// Q: Two sorted linked list given. Write the method to compute the max Sum. With below conditions-
// 1. You can switch the linked list on common nodes. You can switch multiple times.
// 2. You can start from any linked list and end at any linked list.
// L1 = 2->4->7->10->13 
// L2 = 1-> 2 ->6 -> 10->15
// A: maxSum(L1, L2) =  
// Max {{2+4+7+10+13},{1+2+6+10+15}, {2+6+10+15}, {1+2+4+7+10+13}....} = 1+2+4+7+10+15


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	
	Node(int d) {
		val = d;
		next = nullptr;
	}
};

void insertAtEnd(Node* &head, int val) {
	Node* n = new Node(val);
	if (head == nullptr) {
		head = n;
	} else {
		Node* temp = head;
		while (temp->next != nullptr) temp = temp->next;
		temp->next = n;
	}
}

int maximumSum(Node* head1, Node* head2) {
	int answer = 0;
	
	return answer;
}

int main() {
	int len1, len2;
	cin >> len1 >> len2;
	Node* head1, *head2;
	head1 = head2 = nullptr;
	for (int i = 0; i < len1; i++) {
		int temp;
		cin >> temp;
		insertAtEnd(head1, temp);
	}
	for (int i = 0; i < len2; i++) {
		int temp;
		cin >> temp;
		insertAtEnd(head2, temp);
	}
	cout << maximumSum(head1, head2) << endl;
	return 0;
}