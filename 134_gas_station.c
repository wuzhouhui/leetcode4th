int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	if (gasSize < 1 || costSize < 1)
		return(-1);

	int i, start, left, total_left;

	start = left = total_left = 0;
	for (i = 0; i < gasSize; i++) {
		left += gas[i] - cost[i];
		total_left += left;
		if (left < 0) {
			left = 0;
			start = i + 1;
		}
	}
	return(total_left < 0 ? -1 : start % gasSize);
}
main(){}
