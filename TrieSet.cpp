#include "TrieSet.h"
#include <stdio.h>
#include <ctype.h>

TrieSet::TrieSet()
{
	root = new TrieNode;
	root->parent = NULL;
	for(int i = 0; i < 30; i++)
		root->children[i] = NULL;
	root->inSet = false;
}

TrieSet::~TrieSet()
{
	clear(root);
	//delete root;
}

TrieNode* TrieSet::makeNode(TrieNode * par)
{
	TrieNode *newNode = new TrieNode;
	newNode->parent = par;
	for(int i = 0; i < 30; i++)
		newNode->children[i] = NULL;
	newNode->inSet = false;
	return newNode;
}

void TrieSet::insert(std::string input)
{
	if(!isValid(input)) return;
	int wordlength = input.length();
	TrieNode *temp = root;
	for(int i = 0; i < wordlength; i++)
	{
		if(islower(input[i]))
		{
			if(temp->children[input[i] - 'a'] == NULL)
			{
				temp->children[input[i] - 'a'] = makeNode(temp);
				temp = temp->children[input[i] - 'a'];
			}
			else temp = temp->children[input[i] - 'a'];
		}
	
		if(input[i] == '/')
		{
			if(temp->children[26] == NULL)
			{
				temp->children[26] = makeNode(temp);
				temp = temp->children[26];
			}
			else temp = temp->children[26];
		}

		if(input[i] == ':')
		{
			if(temp->children[27] == NULL)
			{
				temp->children[27] = makeNode(temp);
				temp = temp->children[27];
			}
			else temp = temp->children[27];
		}

		if(input[i] == '_')
		{
			if(temp->children[28] == NULL)
			{
				temp->children[28] = makeNode(temp);
				temp = temp->children[28];
			}
			else temp = temp->children[28];
		}

		if(input[i] == '.')
		{
			if(temp->children[29] == NULL)
			{
				temp->children[29] = makeNode(temp);
				temp = temp->children[29];
			}
			else temp = temp->children[29];
		}
	}
	temp->inSet = true;
}

void TrieSet::remove(std::string input)
{
	if(!contains(input)) return;
	TrieNode *temp = root;
	for(int i = 0; i < (int)input.length(); i++)
	{
		if(islower(input[i]))
			temp = temp->children[input[i] - 'a'];
		if(input[i] == '/')
			temp = temp->children[26];
		if(input[i] == ':')
			temp = temp->children[27];
		if(input[i] == '_')
			temp = temp->children[28];
		if(input[i] == '.')
			temp = temp->children[29];
	}
	temp->inSet = false;

	while(temp != root)
	{
		if(temp->inSet == true) break;
		if(numChildren(temp) == 0)
		{
		    TrieNode *origin = temp->parent;
		    for(int i = 0; i < 30; i++)
		    {
		    	if(origin->children[i] == temp)
		    	{
		    		origin->children[i] = NULL;
		    		break;
		    	}
		    }
			delete temp;
			temp = origin;
		}
		else break;
	}
}

bool TrieSet::contains(std::string input)
{
	if(!isValid(input)) return false;
	TrieNode *temp = root;
	for(int i = 0; i < (int)input.length(); i++)
	{
		if(islower(input[i]))
		{
			if(temp->children[input[i]- 'a'] == NULL) return false;
			else temp = temp->children[input[i] - 'a'];
		}
		else if(input[i] == '/')
		{
			if(temp->children[26] == NULL) return false;
			else temp = temp->children[26];
		}
		else if(input[i] == ':')
		{
			if(temp->children[27] == NULL) return false;
			else temp = temp->children[27];
		}
		else if(input[i] == '_')
		{
			if(temp->children[28] == NULL) return false;
			else temp = temp->children[28];
		}
		else if(input[i] == '.')
		{
			if(temp->children[29] == NULL) return false;
			else temp = temp->children[29];
		}
	}
	return temp->inSet;
}

bool TrieSet::isValid(std::string input)
{
	for(int i = 0; i < (int)input.length(); i++)
	{
		if(!islower(input[i]) && input[i] != '/' && input[i] != ':' && input[i] != '_' && input[i] != '.')
			return false;
	}
	return true;
}

int TrieSet::numChildren(const TrieNode * par)
{
	int count = 0;
	for(int i = 0; i < 30; i++)
		if(par->children[i] != NULL) count++;
	return count;
}

void TrieSet::clear(TrieNode * par)
{
	if(par == NULL) return;
	for(int i = 0; i < 30; i++)
		clear(par->children[i]);
	delete par;
}