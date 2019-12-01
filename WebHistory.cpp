#include "WebHistory.hpp"

WebHistory::WebHistory()
{
    // Does nothing.
}

WebHistory::WebHistory(std::string historyText)
{
	// history = url timestamp | url timestamp | url timestamp...
    // urls are string and timestamps are non-negative integers.
    std::string delimiter = " | ";

	std::string tabInfo;
    std::string url;
    std::string timestamp;
    size_t pos = 0;

    while (true)
	{
        pos = historyText.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        tabInfo = historyText.substr(0, pos);
        historyText.erase(0, pos + delimiter.length());

        pos = tabInfo.find(" ");
        
        url = tabInfo.substr(0, pos);
        timestamp = tabInfo.substr(pos + 1, tabInfo.length() - pos);

		Node<Tab> *newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
        insertInOrder(newPage);
		delete newPage;
        if (breakTheLoop)
		{
			break;
		}
    }
}

void WebHistory::printHistory()
{
	std::cout << "Your web history:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
	if (history.getHead()->next == history.getTail())
	{
		std::cout << "History is empty." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		Node<Tab> *node = history.getFirstNode();
		
		while (node != history.getTail())
		{
		    std::cout << "Page: " << node->element.getUrl() << std::endl;
			std::cout << "Last Visited: " << node->element.getTimestamp() << std::endl;
			std::cout << std::endl;
		    node = node->next;
		}
	}
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

WebHistory::WebHistory(std::string url, int timestamp)
{
	// TODO
	Node<Tab> *first = new Node<Tab>();
	first->element.setUrl(url);
	first->element.setTimestamp(timestamp);
	first->next = NULL;
	first->prev = NULL;
	history.insertAfterGivenNode(first->element,history.getHead());

	delete first ;


}
WebHistory::~WebHistory()
{
	// TODO
	clearHistory();
	

}

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
			first = first->next ;
		}
		history.insertAfterGivenNode(newTab->element,position->prev);
	}
	delete newTab;
	
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
	Node<Tab> *p = new Node<Tab>();
	p->element.setTimestamp(timestamp);
	p->element.setUrl(url);
	p->next=NULL;
	p->prev=NULL;
	insertInOrder(p);
	delete p ;
}

void WebHistory::clearHistory()
{
	// TODO
	history.removeAllNodes();
	
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
	Node<Tab> * ptr = history.getFirstNode();
	Node<Tab> *position = history.getFirstNode();
	
	Node<Tab> * tail = history.getTail();
	while (ptr!=history.getTail()){
		
		if (ptr->element.getTimestamp() > timestamp){
			position = position->next ;
		}
		ptr = ptr ->next ;


	}
	
	Node<Tab> *p = position->prev;

	p->next = tail;
	tail->prev = p ;
	tail->next = NULL;
	
	
	
	
	
	
}

WebHistory WebHistory::operator+(const WebHistory &rhs) const
{
	// TODO
	WebHistory old ;
	
	
	// history bi link list 
	Node<Tab> *p = history.getFirstNode();
	while (p!= history.getTail()){

		old.insertInOrder(p);
		p = p->next ;

	}
	p = rhs.history.getFirstNode();

	while(p!= rhs.history.getTail()){
		old.insertInOrder(p);
		p = p->next;

	}

	return old ;
	
}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
	int count = 0 ;
	Node<Tab> *p = history.getFirstNode();
	while (p!= history.getTail()){

		if (p->element.getWebSite() == pageName){
			count++;
			
		}
		p = p->next ;
	}
	delete p ;
	return count ;
}

std::string WebHistory::mostVisited()
{
	// BONUS
	int i=0;
	int j , count ;
	int most = 0;
	std::string temp,element ;
	std::string *ptr  = new std::string[10];
	Node<Tab> * p= history.getFirstNode();
	while(p != history.getTail()){
		ptr[i] = p->element.getWebSite();
		i++;
		p = p->next ;
	}
	for (i=0 ; i < 10 ; i++){
		temp = ptr[i];
		count = 1;
		for(j=i+1 ; j < 10 ; j++){
			if(ptr[j]==temp){
				count++;
			}
		}
		if (most < count){
			most = count ;
			element = ptr[i];
		}

	}
	delete []ptr;
	return element;

}