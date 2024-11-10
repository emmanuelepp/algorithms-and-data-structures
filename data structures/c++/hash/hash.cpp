#include <iostream>
#include <list>
#include <vector>

template <typename KeyType, typename ValueType>
class HashNode
{
public:
    KeyType key;
    ValueType value;
    HashNode *next;

    HashNode(KeyType key, ValueType value) : key(key), value(value), next(nullptr) {}
};

template <typename KeyType, typename ValueType>
class HashTable
{
private:
    std::vector<HashNode<KeyType, ValueType> *> buckets;
    int numBuckets;
    int size;

    int hashFunction(KeyType key)
    {
        return key % numBuckets;
    }

public:
    HashTable(int capacity = 20) : numBuckets(capacity), size(0)
    {
        buckets.resize(numBuckets, nullptr);
    }

    void insert(KeyType key, ValueType value)
    {
        int bucketIndex = hashFunction(key);
        HashNode<KeyType, ValueType> *newNode = new HashNode<KeyType, ValueType>(key, value);
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
        size++;
    }

    bool remove(KeyType key)
    {
        int bucketIndex = hashFunction(key);
        HashNode<KeyType, ValueType> *entry = buckets[bucketIndex];
        HashNode<KeyType, ValueType> *prev = nullptr;

        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[bucketIndex] = entry->next;
                }
                else
                {
                    prev->next = entry->next;
                }
                delete entry;
                size--;
                return true;
            }
            prev = entry;
            entry = entry->next;
        }
        return false;
    }

    ValueType get(KeyType key)
    {
        int bucketIndex = hashFunction(key);
        HashNode<KeyType, ValueType> *entry = buckets[bucketIndex];

        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                return entry->value;
            }
            entry = entry->next;
        }

        throw std::runtime_error("Key not found");
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};
