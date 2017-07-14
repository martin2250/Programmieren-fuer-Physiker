#include <iostream>
#include <cstdlib>

class Node {

private:
    double value;
    Node* left;
    Node* right;
public:
    Node(double val)
	{
		value = val;
		left = NULL;
		right = NULL;
	}

	void insert(double val)
	{
		Node** subnode = (val > value)? &right : &left;

		if(!(*subnode))
			*subnode = new Node(val);
		else
			(*subnode)->insert(val);
	}

	friend std::ostream& operator<< (std::ostream& stream, const Node& node)
	{
		if(node.left)
			stream << *node.left;
		stream << " " << node.value;
		if(node.right)
			stream << *node.right;

		return stream;
	}

	double min()
	{
		if(left == NULL)
			return value;
		return left->min();
	}
};

int main()
{
    srand ((unsigned int)time(0)) ;
    Node tree(1.0) ;        // Basiselement.
    for(int i=0; i<10; i++) // 10 Zufallszahlen in den Baum einhaengen...
    {
	double x = 2.0*double(rand())/RAND_MAX ;
	std::cout << "Einzufuegen: " << x << std::endl ;
	tree.insert(x) ;
    }
    std::cout << "Die minimale Zahl im Baum ist: " << tree.min() << std::endl ;
    std::cout << "Alle Eintraege sortiert: " << std::endl << "  " << tree << std::endl ;
}
