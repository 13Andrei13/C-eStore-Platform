#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
	//throw("undefined");
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	for(auto& i : requestsNo) 
	{
		if(find(lru.begin(), lru.end(), i) == lru.end()) 
		{
			if(lru.size() == this->capacity) 
				lru.pop_back(); 
		} else { 
			lru.erase(find(lru.begin(), lru.end(), i)); 
		}

		lru.insert(lru.begin(), i); 
	}

	return lru;
	//throw("undefined");
}

int LRUCache::getCapacity()
{
	return this->capacity;
	//throw("undefined");
}

int LRUCache::getSize()
{
	return this->size;
	//throw("undefined");
}

vector<int> LRUCache::getLRU()
{
	return this->lru;
	//throw("undefined");
}

int LRUCache::getLRUCapacity()
{
	return this->lru.size();
	//throw("undefined");
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
	//throw("undefined");
}

void LRUCache::setLRU(vector<int> aux)
{
	this->lru = aux;
	//throw("undefined");
}
