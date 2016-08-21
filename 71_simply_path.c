#include <stdlib.h>
#include <string.h>

char *simplifyPath(char *path)
{
	if (path == NULL || path[0] == 0)
		return(strdup("/"));
	char *res = strdup(path);
	int p = 0;
	res[p++] = '/';
	while (*path) {
		switch (*path) {
		case '/':
			path++;
			break;
		case '.':
			if (*(path + 1) == 0 || *(path + 1) == '/') {
				path++;
				break;
			}
			if (*(path + 1) == '.') {
				if (*(path + 2) == 0 || *(path + 2) == '/') {
					path += 2;
					if (p == 1)
						break;
					p--;
					while (p > 1 && res[p] != '/')
						p--;
					break;
				}
			}
			if (res[p - 1] != '/')
				res[p++] = '/';
			while (*path && *path != '/')
				res[p++] = *path++;
			break;
		default:
			if (res[p - 1] != '/')
				res[p++] = '/';
			while (*path && *path != '/')
				res[p++] = *path++;
			break;
		}
	}
	res[p] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", simplifyPath(argv[1]));
	return(0);
}
