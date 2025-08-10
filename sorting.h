#pragma once

#include <limits>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
#include <string>

namespace bice
{
	template<typename CONTAINER, typename COMPARATOR>
	void bubbleSort(CONTAINER& container, COMPARATOR comparator)
	{
		using size_type = typename CONTAINER::size_type;
		const size_type arraySize = container.size();

		for (size_type idx_1 = 0; idx_1 < arraySize; ++idx_1)
		{
			for (size_type idx_2 = 0; idx_2 < arraySize - 1 - idx_1; ++idx_2)
			{
				if (comparator(container[idx_2 + 1], container[idx_2]))
				{
					std::swap(container[idx_2], container[idx_2 + 1]);
				}
			}
		}
	}

	template<typename CONTAINER>
	void bubbleSort(CONTAINER& container)
	{
		using size_type = typename CONTAINER::size_type;
		const size_type arraySize = container.size();

		for (size_type idx_1 = 0; idx_1 < arraySize; ++idx_1)
		{
			for (size_type idx_2 = 0; idx_2 < arraySize - 1 - idx_1; ++idx_2)
			{
				if (container[idx_2] > container[idx_2 + 1])
				{
					std::swap(container[idx_2], container[idx_2 + 1]);
				}
			}
		}
	}

	template<typename ITERATOR, typename COMPARATOR>
	void bubbleSort(ITERATOR begin, ITERATOR end, COMPARATOR comparator)
	{

		while (begin != --end)
		{
			for (auto iter = begin; iter < end; ++iter)
			{
				if (comparator(*(iter + 1), *iter))
				{
					std::swap(*(iter + 1), *iter);
				}
			}
		}
	}

	template<typename ITERATOR>
	void bubbleSort(ITERATOR begin, ITERATOR end)
	{
		while (begin != --end)
		{
			for (auto iter = begin; iter < end; ++iter)
			{
				if (*(iter + 1) < *iter)
				{
					std::swap(*(iter + 1), *iter);
				}
			}
		}
	}

	template<typename ITERATOR, typename COMPARATOR>
	void selectionSort(ITERATOR begin, ITERATOR end, COMPARATOR comparator)
	{

		ITERATOR endFirst = end - 1;
		ITERATOR min;

		for (auto iter_1 = begin; iter_1 != endFirst; ++iter_1)
		{
			min = iter_1;
			for (auto iter_2 = iter_1 + 1; iter_2 != end; ++iter_2)
			{				
				if (comparator(*iter_2, *min)) min = iter_2;
			}
			std::swap(*iter_1, *min);
		}

	}

	template<typename ITERATOR>
	void selectionSort(ITERATOR begin, ITERATOR end)
	{

		ITERATOR endFirst = end - 1;
		ITERATOR min;

		for (auto iter_1 = begin; iter_1 != endFirst; ++iter_1)
		{
			min = iter_1;
			for (auto iter_2 = iter_1 + 1; iter_2 != end; ++iter_2)
			{
				if (*iter_2 < *min) min = iter_2;
			}
			std::swap(*iter_1, *min);
		}
	}

	template<typename CONTAINER, typename COMPARATOR>
	void selectionSort(CONTAINER& container, COMPARATOR comparator)
	{

		using size_type = typename CONTAINER::size_type;
		const size_type arraySize = container.size();
		size_type min;

		for (size_type idx_1 = 0; idx_1 < arraySize - 1; ++idx_1)
		{
			min = idx_1;
			for (size_type idx_2 = idx_1 + 1; idx_2 < arraySize; ++idx_2)
			{
				if (comparator(container[idx_2], container[min])) min = idx_2;
			}
			std::swap(container[min], container[idx_1]);
		}
	}

	template<typename CONTAINER>
	void selectionSort(CONTAINER& container)
	{
		using size_type = typename CONTAINER::size_type;
		const size_type arraySize = container.size();
		size_type min;

		for (size_type idx_1 = 0; idx_1 < arraySize - 1; ++idx_1)
		{
			min = idx_1;
			for (size_type idx_2 = idx_1 + 1; idx_2 < arraySize; ++idx_2)
			{
				if (container[min] > container[idx_2]) min = idx_2;
			}
			std::swap(container[min], container[idx_1]);
		}
	}

	template<typename CONTAINER, typename COMPARATOR>
	void insertSort(CONTAINER& array, COMPARATOR comparator)
	{

		using value_type = typename CONTAINER::value_type;
		using size_type = typename CONTAINER::size_type;

		const size_type arraySize = array.size();

		size_type out, in;
		value_type temp;
		for (out = 1; out < arraySize; ++out)
		{
			in = out;
			temp = std::move(array[out]);			
			while (in > 0 && comparator(temp, array[in - 1]))
			{
				array[in] = std::move(array[in - 1]);
				--in;
			}
			array[in] = std::move(temp);
		}
	}

	template<typename CONTAINER>
	void insertSort(CONTAINER& array)
	{

		using value_type = typename CONTAINER::value_type;
		using size_type = typename CONTAINER::size_type;

		const size_type arraySize = array.size();

		size_type out, in;
		value_type temp;
		for (out = 1; out < arraySize; ++out)
		{
			in = out;
			temp = std::move(array[out]);
			while (in > 0 && array[in - 1] >= temp)
			{
				array[in] = std::move(array[in - 1]);
				--in;
			}
			array[in] = std::move(temp);
		}
	}

	template<typename ITERATOR, typename COMPARATOR>
	void insertSort(ITERATOR begin, ITERATOR end, COMPARATOR comparator)
	{

		auto temp = *begin;
		ITERATOR out, in;

		for (out = begin + 1; out != end; ++out)
		{
			in = out;
			temp = std::move(*out);			
			while (in != begin && comparator(temp, *(in - 1)))
			{
				*in = std::move(*(in - 1));
				--in;
			}
			*in = std::move(temp);
		}
	}

	template<typename ITERATOR>
	void insertSort(ITERATOR begin, ITERATOR end)
	{

		auto temp = *begin;
		ITERATOR out, in;

		for (out = begin + 1; out != end; ++out)
		{
			in = out;
			temp = std::move(*out);
			while (in != begin && *(in - 1) >= temp)				
			{
				*in = std::move(*(in - 1));
				--in;
			}
			*in = std::move(temp);
		}
	}

	template<typename ITERATOR, typename COMPARATOR>
	void mergeSort(ITERATOR begin, ITERATOR end, ITERATOR beginWorkSpace, COMPARATOR comparator)
	{
		if (end - 1 == begin)
		{
			return;
		}
		else
		{
			auto mid = begin + (end - 1 - begin) / 2;
			mergeSort(begin, mid + 1, beginWorkSpace, comparator);
			mergeSort(mid + 1, end, beginWorkSpace, comparator);

			ITERATOR j{ beginWorkSpace };
			const auto numberOfElements = end - begin;
			ITERATOR lowPtr = begin;
			ITERATOR highPtr = mid + 1;

			while (lowPtr <= mid && highPtr <= end - 1)
			{
				if (comparator(*lowPtr, *highPtr))
				{
					*j = *lowPtr;
					++j;
					++lowPtr;
				}
				else
				{
					*j = *highPtr;
					++j;
					++highPtr;
				}
			}

			while (lowPtr <= mid)
			{
				*j = *lowPtr;
				++j;
				++lowPtr;
			}

			while (highPtr <= end - 1)
			{
				*j = *highPtr;
				++j;
				++highPtr;
			}

			ITERATOR arrayIter = begin;
			ITERATOR workIter = beginWorkSpace;

			for (auto idx = 0; idx < numberOfElements; idx++)
			{
				*(arrayIter + idx) = *workIter;
				++workIter;
			}
		}
	}

	template<typename ITERATOR>
	void mergeSort(ITERATOR begin, ITERATOR end, ITERATOR beginWorkSpace)
	{
		if (end - 1 == begin)
		{
			return;
		}
		else
		{
			auto mid = begin + (end - 1 - begin) / 2;
			mergeSort(begin, mid + 1, beginWorkSpace);
			mergeSort(mid + 1, end, beginWorkSpace);

			ITERATOR j{ beginWorkSpace };
			const auto numberOfElements = end - begin;
			ITERATOR lowPtr = begin;
			ITERATOR highPtr = mid + 1;

			while (lowPtr <= mid && highPtr <= end - 1)
			{
				if (*lowPtr < *highPtr)
				{
					*j = *lowPtr;
					++j;
					++lowPtr;
				}
				else
				{
					*j = *highPtr;
					++j;
					++highPtr;
				}
			}

			while (lowPtr <= mid)
			{
				*j = *lowPtr;
				++j;
				++lowPtr;
			}

			while (highPtr <= end - 1)
			{
				*j = *highPtr;
				++j;
				++highPtr;
			}

			ITERATOR arrayIter = begin;
			ITERATOR workIter = beginWorkSpace;

			for (auto idx = 0; idx < numberOfElements; idx++)
			{
				*(arrayIter + idx) = *workIter;
				++workIter;
			}
		}
	}

	template<typename CONTAINER, typename COMPARATOR>
	void mergeSort(CONTAINER& container, CONTAINER& workContainer, const typename CONTAINER::size_type& lowerBound,
		const typename CONTAINER::size_type& upperBound, COMPARATOR comparator)
	{
		if (lowerBound == upperBound) return;
		else
		{
			using size_type = typename CONTAINER::size_type;

			const size_type mid = lowerBound + (upperBound - lowerBound) / 2;

			mergeSort(container, workContainer, lowerBound, mid, comparator);
			mergeSort(container, workContainer, mid + 1, upperBound, comparator);

			size_type j = 0;
			size_type lowPtr = lowerBound;
			size_type highPtr = mid + 1;
			const size_type n = upperBound - lowerBound + 1;

			while (lowPtr <= mid && highPtr <= upperBound)
			{				
				if (comparator(container[lowPtr], container[highPtr]))
				{
					workContainer[j++] = container[lowPtr++];
				}
				else
				{
					workContainer[j++] = container[highPtr++];
				}
			}

			while (lowPtr <= mid)
			{
				workContainer[j++] = container[lowPtr++];
			}

			while (highPtr <= upperBound)
			{
				workContainer[j++] = container[highPtr++];
			}

			for (j = 0; j < n; ++j)
			{
				container[j + lowerBound] = workContainer[j];
			}
		}

	}


	template<typename CONTAINER>
	void mergeSort(CONTAINER& container, CONTAINER& workContainer, const typename CONTAINER::size_type& lowerBound,
		const typename CONTAINER::size_type& upperBound)
	{
		if (lowerBound == upperBound) return;
		else
		{
			using size_type = typename CONTAINER::size_type;

			const size_type mid = lowerBound + (upperBound - lowerBound) / 2;

			mergeSort(container, workContainer, lowerBound, mid);
			mergeSort(container, workContainer, mid + 1, upperBound);

			size_type j = 0;
			size_type lowPtr = lowerBound;
			size_type highPtr = mid + 1;
			const size_type n = upperBound - lowerBound + 1;

			while (lowPtr <= mid && highPtr <= upperBound)
			{
				if (container[lowPtr] < container[highPtr])
				{
					workContainer[j++] = container[lowPtr++];
				}
				else
				{
					workContainer[j++] = container[highPtr++];
				}
			}

			while (lowPtr <= mid)
			{
				workContainer[j++] = container[lowPtr++];
			}

			while (highPtr <= upperBound)
			{
				workContainer[j++] = container[highPtr++];
			}

			for (j = 0; j < n; ++j)
			{
				container[j + lowerBound] = workContainer[j];
			}
		}

	}

	template<typename ITERATOR, typename COMPARATOR>
	void quickSort(ITERATOR begin, ITERATOR end, COMPARATOR comparator)
	{
		if (begin != end)
		{
			ITERATOR left = begin;
			ITERATOR right = end;
			ITERATOR pivot = left++;

			while (left != right)
			{
				if (comparator(*left, *pivot))
				{
					++left;
				}
				else
				{
					while ((left != --right) && comparator(*pivot, *right));
					std::iter_swap(left, right);
				}
			}

			--left;
			std::iter_swap(begin, left);

			quickSort(begin, left, comparator);
			quickSort(right, end, comparator);
		}
	}

	template<typename ITERATOR>
	void quickSort(ITERATOR begin, ITERATOR end)
	{
		if (begin != end)
		{
			ITERATOR left = begin;
			ITERATOR right = end;
			ITERATOR pivot = left++;

			while (left != right)
			{
				if (*left < *pivot)
				{
					++left;
				}
				else
				{
					while ((left != --right) && *pivot < *right);
					std::iter_swap(left, right);
				}
			}

			--left;
			std::iter_swap(begin, left);

			quickSort(begin, left);
			quickSort(right, end);
		}
	}


	template<typename CONTAINER>
	void quickSort(CONTAINER& container, const std::int64_t& left,
		const std::int64_t& right)
	{
		if (right - left <= 0) return;
		else
		{
			const auto pivot = container[right];
			std::int64_t leftPtr = left - 1;
			std::int64_t rightPtr = right;

			while (true)
			{
				while (container[++leftPtr] < pivot);
				while (rightPtr > left && container[--rightPtr] > pivot);
				if (leftPtr >= rightPtr) break;
				else std::swap(container[leftPtr], container[rightPtr]);
			}
			std::swap(container[leftPtr], container[right]);
			const auto partition = leftPtr;

			quickSort(container, left, partition - 1);
			quickSort(container, partition + 1, right);
		}
	}

}
