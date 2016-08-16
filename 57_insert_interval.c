#include <stdlib.h>
#include <string.h>

struct Interval {
	int	start;
	int	end;
};

static struct Interval *res;
static int maxp, p;

static void addans(const struct Interval *i)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	memcpy(&res[p++], i, sizeof(*i));
}

struct Interval *insert(struct Interval *intervals, int intervalsSize,
		struct Interval newInterval, int *returnSize)
{
	struct Interval *buf;
	int	i, j;

	buf = malloc((intervalsSize + 1) * sizeof(*buf));
	for (j = i = 0; i < intervalsSize; i++) {
		if (intervals[i].start <= newInterval.start)
			buf[j++] = intervals[i];
		else {
			buf[j++] = newInterval;
			memcpy(buf + j, intervals + i, (intervalsSize - i) *
					sizeof(*intervals));
			break;
		}
	}
	if (i >= intervalsSize)
		buf[j++] = newInterval;

	maxp = p = 0;
	res = NULL;
	for (i = 0; i <= intervalsSize; ) {
		newInterval = buf[i++];
		while (i <= intervalsSize && buf[i].start <= newInterval.end) {
			if (buf[i].end > newInterval.end)
				newInterval.end = buf[i].end;
			i++;
		}
		addans(&newInterval);
	}
	*returnSize = p;
	free(buf);
	return(res);
}

int main(void)
{
	struct Interval arr[] = { { 1, 5, }, };
	struct Interval new = { 0, 3, };
	int	n;
	insert(arr, 1, new, &n);
}
