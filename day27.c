#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* insert(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
int findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--)
            ptr1 = ptr1->next;
    } else {
        while (diff--)
            ptr2 = ptr2->next;
    }
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;  // No intersection
}
int main() {
    int n, m, val;
    Node *head1 = NULL, *head2 = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        head1 = insert(head1, val);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        head2 = insert(head2, val);
    }
    int result = findIntersection(head1, head2);
    if (result == -1)
        cout << "No Intersection";
    else
        cout << result;
    return 0;
}
