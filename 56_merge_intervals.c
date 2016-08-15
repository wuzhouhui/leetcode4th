#include <stdlib.h>
#include <string.h>

struct Interval {
	int	start;
	int	end;
};

static struct Interval *res;
static int p, maxp;

static int cmp(const void *a, const void *b)
{
	struct Interval *ai = (struct Interval *)a;
	struct Interval *bi = (struct Interval *)b;
	if (ai->start != bi->start)
		return(ai->start - bi->start);
	return(ai->end - bi->end);
}

static void addans(const struct Interval *i)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	memcpy(&res[p++], i, sizeof(*i));
}

struct Interval *merge(struct Interval *intervals, int intervalsSize,
		int *returnSize)
{
	if (intervalsSize < 1) {
		*returnSize = 0;
		return(NULL);
	}

	int	i;
	struct Interval cur;

	qsort(intervals, intervalsSize, sizeof(*intervals), cmp);
	maxp = p = 0;
	res = NULL;
	for (i = 0; i < intervalsSize; ) {
		cur = intervals[i++];
		while (i < intervalsSize && intervals[i].start <= cur.end) {
			if (intervals[i].end > cur.end)
				cur.end = intervals[i].end;
			i++;
		}
		addans(&cur);
	}
	*returnSize = p;
	return(res);
}

int main(void)
{
}
