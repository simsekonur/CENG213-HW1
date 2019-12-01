void WebHistory::insertInOrder(Node<Tab> *newPage)
{

	// TODO
	Node<Tab> *newTab = new Node<Tab>(Tab(newPage->element.getUrl(),newPage->element.getTimestamp()), NULL, NULL); // the tab node to be added
	
	if (history.getHead()->next == history.getTail()){ // bu adam bos 
		history.insertAtTheFront(newTab->element);
	}

	else { // bu adam bos degılse url ve timestamp ı doldurdugun tab ı uygun pos ekle  
		Node<Tab> * first = history.getFirstNode();
		Node<Tab> * position = history.getFirstNode();
		while(first != history.getTail()){
			if(first->element.getTimestamp() > newTab->element.getTimestamp()){
				position = position->next ;
			}
			else { // eğer kücük yada esitse 
				position = first->prev ; 

			}
			
			first = first->next ;
		}
		history.insertAfterGivenNode(newTab->element,position->prev);
	}
	
}
