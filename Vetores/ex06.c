#include <stdio.h>

int main () {
	int pos = 0, count, zeroAmount, line, column, bolis, success = 1, lineAmount, columnAmount;

	scanf("%d %d", &lineAmount, &columnAmount);

	for (line = 0; line < lineAmount; ++line) {
		zeroAmount = 0;
		bolis = 1;

		for (column = 0; column < columnAmount; ++column) {
			scanf("%d", &count);

			if (count == 0 && bolis) {
				zeroAmount++;
      } else {
				bolis = 0;
      }
		}

		if (line != 0) {
			if ((zeroAmount > pos || (zeroAmount == pos && zeroAmount == columnAmount)) && success) {
				pos = zeroAmount;
      } else {
				pos = 0, success = 0;
      }
		} else {
			pos = zeroAmount;
    }

	}

	if (pos) {
		printf("S\n");
  }

	else {
		printf("N\n");
  }

  return 0;
}