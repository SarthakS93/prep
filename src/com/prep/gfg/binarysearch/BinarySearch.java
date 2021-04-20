package com.prep.gfg.binarysearch;

public class BinarySearch {

    private int[] arr = {1,2,3,3,3,5,8};

    public int search(int x) {
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low)/2;
            if (arr[mid] == x) {
                return mid;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }

    public int findFirstOccurrence(int x) {
        int low = 0, high = arr.length - 1;

        int smallestIndex = -1;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (arr[mid] == x) {
                smallestIndex = mid;
                high = mid - 1;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }

        return smallestIndex;
    }

    public int findLastOccurrence(int x) {
        int low = 0, high = arr.length - 1;

        int smallestIndex = -1;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (arr[mid] == x) {
                smallestIndex = mid;
                low = mid + 1;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }

        return smallestIndex;
    }

}
