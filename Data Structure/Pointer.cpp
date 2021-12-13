//Add two integer as a digit

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0;
        ListNode *l3 = new ListNode();
        ListNode *head = l3;
		while(l1 || l2 || sum > 0){
			if(l1){
				sum += l1 -> val;
				l1 = l1 -> next;
			}
			if(l2){
				sum += l2 -> val;
				l2 = l2 -> next;
			}
			l3 -> next = new ListNode(sum % 10);
			sum /= 10;
			l3 = l3 -> next;
		}
		return head -> next;
    }
};

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   Solution ob;
   ListNode *l1 = new ListNode(), *l2 = new ListNode(), *l3 = new ListNode(), *last1 = l1, *last2 = l2;
   int n; cin >> n;
   for(int i=0; i<n; i++) {
	   int x; cin >> x;
	   ListNode *y = new ListNode(x);
	   last1 -> next = y;
	   last1 = y;
	   cerr(last1 -> val);
   }
   cout << endl;
   for(int i=0; i<n; i++){
	   int x; cin >> x;
	   ListNode *y = new ListNode(x);
	   last2 -> next = y;
	   last2 = y;
	   cerr(last2 -> val);
   }
   cout << endl;
   l3 = ob.addTwoNumbers(l1, l2);
   ListNode *head = l3;
   for(int i=0; i<n; i++){
	   head = head -> next;
	   cout << head -> val << ' ';
   }
   cout << endl;
   return 0;
}
