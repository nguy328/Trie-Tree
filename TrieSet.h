#include <string>



struct TrieNode {
  bool inSet;   // we're not storing a value.
  TrieNode *parent;
  TrieNode *children[30];
};

class TrieSet {
public:

	TrieSet();
	~TrieSet();
	void insert (std::string input);
	   /* Add this string to the set.
	      Do nothing if the string is already in the set. */

	void remove (std::string input);
	   /* Remove this string from the set.
	      Do nothing if the string is not in the set. */

	bool contains (std::string input); // returns whether this string is in the set.	

private:
	TrieNode* makeNode(TrieNode * par);
	bool isValid (std::string input);
	int numChildren(const TrieNode * par);
	void clear(TrieNode * par);
	TrieNode *root;

};