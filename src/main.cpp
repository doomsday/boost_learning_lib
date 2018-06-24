#include <iostream>
#include <memory>
#include <ctime>

struct FILEDeleter {
  void operator()(FILE *fp) const {
    fprintf(stderr, "Deleter invoked\n");
    if (fp) {
      fclose(fp);
    }
  }
};

int main() {
  std::shared_ptr<FILE> spfile(fopen("tmp.txt", "a+"), FILEDeleter());

  time_t t;
  time(&t);

  if (spfile) {
    fprintf(spfile.get(), "tstamp: %s\n", ctime(&t));
  }

  return EXIT_SUCCESS;
}