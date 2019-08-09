#ifndef LIST_H
#define LIST_H

	template<class elemType> class ListItem;

	template<class elemType>
	class List
	{
	public:
		List();
		List(const List& lst);
		List& operator=(const List& other);
		~List();

		void insert(ListItem<elemType>* ptr, elemType value);
		ListItem<elemType>* find(elemType value);
	private:
		ListItem<elemType>* front;
		ListItem<elemType>* end;
	};

#endif	/* LIST_H */
