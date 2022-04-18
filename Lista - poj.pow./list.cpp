#include <iostream>
#include "singleList.h"
//#include "testList.h"

void test_empty() {
	SingleList <int>list;
	assert(list.empty() == 1);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'empty()'"<<std::endl;

}

void test_size() {
	SingleList <int>list;
	assert(list.size() == 0);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'size()'"<<std::endl;

}

void test_push_front() {
	SingleList <int>list;
	int value = rand() % 10;
	list.push_front(value);
	assert(list.front() == value);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'push_front()'"<<std::endl;

}

void test_push_back() {
	SingleList <int>list;
	int value = rand() % 10;
	list.push_front(value);
	assert(list.back() == value);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'push_back()'"<<std::endl;

}
void test_front() {
	SingleList <int>list;
	int value = rand() % 10;
	list.push_front(value);
	assert(list.front() == value);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'front()'"<<std::endl;

}

void test_back() {
	SingleList <int>list;
	int value = rand() % 10;
	list.push_front(value);
	assert(list.back() == value);
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'back()'"<<std::endl;

}

void test_pop_front() {
	int temp[2];
	SingleList <int>list;
	for(int i=0;i<2;i++) {
	int value = rand() % 10;
	temp[i] = value;
	list.push_front(value);
}
	for(int i=2;i>1;i--) {
	list.pop_front();
	assert(list.front() == temp[i-2]);
}	
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'pop_front()'"<<std::endl;

}

void test_pop_back() {
	int temp[3];
	SingleList <int>list;
	for(int i=0;i<3;i++) {
	int value = rand() % 10;
	temp[i] = value;
	list.push_back(value);
}
	for(int i=3;i>1;i--) {
	list.pop_back();
	assert(list.back() == temp[i-2]);
}	
	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'pop_back()'"<<std::endl;

}

void test_clear() {
	SingleList <int>list;
	for(int i=0;i<5;i++) {
	int value = rand() % 10;
	list.push_back(value);
	}
	list.clear();
	assert(list.size() == 0);
  	std::cout<<"\033[1;32m[OK]\033[0mTest metody:'clear()'"<<std::endl;
}

void test_reverse() {
  SingleList <int>list;
  int size = 3;
  int Temp[size];
  for(int i=0; i<size;i++) {
    const int value = rand() % 100;
    Temp[i] = value;
    list.push_front(value);
  }
  list.reverse();
  for(int i=0; i<size;i++) {
    assert(list.position(i) == Temp[i]);

  }
  std::cout<<"\033[1;32m[OK]\033[0mTest metody:'reverse()'"<<std::endl;
}

void test_copy_constructor() {
	SingleList <int>list1;
 	for(int i=0;i<10;i++) {
	 	int value = rand() % 10;
	 	list1.push_front(value);
	 }
	SingleList <int>list2(list1);
	for(int i=0; i<list2.size(); i++) {
		assert(list1.position(i) == list2.position(i));
	}
	std::cout<<"\033[1;32m[OK]\033[0mTest copy constructor"<<std::endl;
}

void test_copy_assigment_operator() {
	SingleList <int>list1;
 	for(int i=0;i<10;i++) {
	 	int value = rand() % 10;
	 	list1.push_front(value);
	 }
	SingleList <int>list2;
	list2 = list1;
	for(int i=0; i<list2.size(); i++) {
		assert(list1.position(i) == list2.position(i));
	}
	std::cout<<"\033[1;32m[OK]\033[0mTest copy asigment operator"<<std::endl;
}

int main(void) {
test_empty();
test_size();
test_push_front();
test_push_back();
test_front();
test_back();
test_pop_front();
test_pop_back();
test_clear();
test_reverse();
test_copy_constructor();
test_copy_assigment_operator();
std::cout<<"-----------------------------------------"<<std::endl;
SingleList<int>list1;
SingleList<int>list2;
for(int i = 0; i<10; i++) {
	list1.push_front(i);
}
list1.display();
list2 = list1;
list2.display();
SingleList<int>list3(list2);
list3.display();


//std::cout<<std::endl<<"\033[1;32mWszystkie testy ukonczone powodzeniem\033[0m"<<std::endl;
return 0;
}
