#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;
  
        
    std::cout << llist.isEmpty() << std::endl ;
    std::cout << "Number :"<< llist.getNumberOfNodes() << std::endl;
   
    llist.insertAfterGivenNode(6,llist.getHead());
    llist.printAllNodes() ; std::cout << std::endl;
    std::cout << "Number :"<< llist.getNumberOfNodes() << std::endl;
    std::cout << llist.isEmpty() << std::endl ;

    llist.insertAfterGivenNode(66,llist.getHead());
    llist.printAllNodes(); std::cout << std::endl;
    std::cout << llist.findNode(6) << std::endl ;

    std::cout << "I couldn't find ..."<< llist.findNode(76) << std::endl;

    std::cout << "Number:"<< llist.getNumberOfNodes() << std::endl;
     std::cout << "Reversed :" ; llist.printReversed(); std::cout << "******************************"<< std::endl ;
    llist.insertAtTheFront(1);
    llist.printAllNodes(); std::cout << std::endl ;
    std::cout << "Number:"<< llist.getNumberOfNodes() << std::endl;

    llist.insertAtTheFront(100);
    llist.printAllNodes(); std::cout << std::endl ;
    llist.printReversed(); std::cout << std::endl ;
    llist.insertAtTheEnd(1000);
    llist.printAllNodes();std::cout << std::endl ;
    llist.insertAtTheEnd(999);
    llist.printAllNodes();std::cout << std::endl ;
    std::cout << "Number:"<< llist.getNumberOfNodes() << std::endl;

  
    std::cout << llist.getFirstNode()->element << std::endl ;
    std::cout << llist.isEmpty() << std::endl;
    


    std::cout << "Remove u kontrol edecem" << std::endl ;
    llist.removeNode(llist.getFirstNode()->next->next);
    llist.printAllNodes(); std::cout << std::endl ;
    llist.removeNode(llist.getTail()->prev);
    llist.printAllNodes(); std::cout << std::endl ;
    std::cout << "Remove all node u kontrol edecem" << std::endl ;
    llist.removeAllNodes();
    llist.printAllNodes(); std::cout << std::endl ;
   






    return 0;
}
