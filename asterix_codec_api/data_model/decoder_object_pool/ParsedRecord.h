#ifndef DATA_MODEL_DECODER_OBJECT_POOL_PARSEDRECORD_H_
#define DATA_MODEL_DECODER_OBJECT_POOL_PARSEDRECORD_H_

#include <vector>

#include "data_model/decoder_objects/ParsedElement.h"

/**
 * Manage a object pool of ParsedElement objects.
 */
class ParsedRecord {
	public:

		ParsedRecord(unsigned int poolSize);

		~ParsedRecord();

		std::vector<ParsedElement*>* getAllParsedElementsPtr();

		unsigned int getObjectPoolCurrentSize();

		unsigned char* getRawRecord();

		void setRawRecord(unsigned char* _rawRecord);

		unsigned int getRawRecordLength();

		void setRawRecordLength(unsigned int _lengthRawRecord);

		unsigned int getRecordCategoryNumber();

		void setRecordCategoryNumber(unsigned int _recordCategoryNumber);


		//OTHER FUNCTIONS
		/**
		 * Releases memory used to save the parsed data of elements
		 */
		void setFreeAllElements();

		/**
		 * Get from object pool an empty object and save information of a parsed element.
		 * If there is not an empty object, a new place is allocated.
		 * @param itemDescription Pointer to the object with decoding information of the current element
		 * @param indexInItemVectors Index to get information about the current element inside the vectors of 'itemDescription'
		 * @param parsedValue Parsed value of current element
		 */
		void setParsedElement(Item* itemDescription, int indexInItemVectors, unsigned char* parsedValue);

		void setMembershipQueue(int index);

		int getMembershipQueue();

	private:

		std::vector<ParsedElement*> parsedElementsObjectPool;

		unsigned char* rawRecord;
		unsigned int rawRecordLength;

		unsigned int recordCategoryNumber;


		int membershipQueue;
		unsigned int objectPoolCurrentSize;		// current size of object pool, it is used like a index
};

#endif /* DATA_MODEL_DECODER_OBJECT_POOL_PARSEDRECORD_H_ */
