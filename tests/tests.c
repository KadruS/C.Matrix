#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *s21_matrix_test[] = {create_equal_tests(), sum_sub_tests(),
                              mul_tests(),          determinant_tests(),
                              calc_inverse_tests(), NULL};
  int i = 0;
  for (; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("\033[30;47m========= ALLTES: %d =========\033[0m\n", i);
  printf("\033[44m========= PASSED: %d =========\033[0m\n", i - failed);
  printf("\033[41m========= FAILED: %d =========\033[0m\n", failed);

  return failed == 0 ? 0 : 1;
}
