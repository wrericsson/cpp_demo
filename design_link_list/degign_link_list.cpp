/*
 **************************************************************************************
 *       Filename:  c11.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-04-10 11:37:58
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <vector>  
#include <map>
#include <iostream>

#include <memory>

using namespace std;

class MyLinkedList {
	public:
		/** Initialize your data structure here. */
		MyLinkedList() : head {std::make_shared<node>()}, tail {std::make_shared<node>()} {
			head->next = tail;
			tail->prev = head;
		}

		/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
		int get(int index) {

			if (index  > count) {
				return -1;
			}

			auto ptr = head;

			cout << "index:"<< index << endl;
			for (int i = 0; i < index ; ++i) {
				cout << "ptr value:"<< ptr->val<< endl;
				ptr = ptr->next;
			}

			return ptr->val;

		}

		/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
		void addAtHead(int val) {
			auto new_node = std::make_shared<node>();
			new_node->val = val;
			new_node->next = head;

			head->prev = new_node;
			head = new_node;

			cout <<"head : " <<head->val << endl;
			count++;
			if (count == 1)
				tail = head;
			//cout << new_node->val << endl;
			cout <<"count :" << count << endl;
			cout <<"tail : " <<tail->val << endl;
		}
		int getSize(void) const{
		    return count;
		}
		/** Append a node of value val to the last element of the linked list. */
		void addAtTail(int val) {
			auto new_node = std::make_shared<node>();
			//auto  = std::make_shared<node>();

			if(tail){

				new_node->val = val;
				new_node->prev = tail;


				tail->next = new_node;
				//cout << head->val << endl;
				tail = new_node;


				cout <<"tail :" << tail->val << endl;

				count++;

				cout <<"count :" << count << endl;
			}else
			{
				addAtHead(val);			
			}

		}

		/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
		void addAtIndex(int index, int val) {

			if (index > count) {
				return;
			}
			else if (index == 0) {

				addAtHead(val);
			}
			else if (index == count) {
				// add to tail
				addAtTail(val);

			} else {  // index < count

				auto new_node = std::make_shared<node>();
				new_node->val = val;

				auto ptr = head;
				for (int i = 0; i < index ; i++) {
					ptr = ptr->next;
				}
				cout <<"add ptr value: " <<ptr->val <<endl;
				new_node->next  = ptr;
				new_node->prev = ptr->prev;


				ptr->prev->next = new_node;
				ptr->prev = new_node;

				++count;

			}
		}

		/** Delete the index-th node in the linked list, if the index is valid. */
		void deleteAtIndex(int index) {

			if (index + 1 > count) {
				return;
			}

			auto ptr = head;
			for (int i = 0; i < index + 1; ++i) {
				ptr = ptr->next;
			}

			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;

			--count;
		}


	private:

		struct node {
			int val;
			std::shared_ptr<node> next {nullptr};
			std::shared_ptr<node> prev {nullptr};
		};


		std::shared_ptr<node> head;
		std::shared_ptr<node> tail;

		std::size_t count = 0;


};

int main(int argc, const char *argv[])
{
	//Your MyLinkedList object will be instantiated and called as such:
	MyLinkedList *obj = new MyLinkedList();
	//int param_1 = obj->get(1);
	obj->addAtHead(1);
	obj->addAtHead(2);
	//obj->addAtHead(1);
	//obj->addAtHead(1);
	//obj->addAtHead(1);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	//obj->addAtTail(3);
	obj->addAtTail(4);
	obj->addAtTail(3);
	//cout <<"add to tail" <<endl;
	obj->addAtIndex(2,30);
	obj->addAtIndex(2,30);
	obj->addAtIndex(2,30);
	obj->addAtIndex(2,30);
	obj->addAtIndex(2,30);
	obj->addAtIndex(2,30);
	//cout << "get 2--"<< obj->get(2) << endl;
	//cout << "get 2--"<< obj->get(3) << endl;
	//obj->deleteAtIndex(2);
	int count = obj->getSize();
	for (int i = 0; i < count; i++) {
		cout << "get-----" << i << ":" <<obj->get(i) << endl;
	}


	return 0;
}


/********************************** END **********************************************/

