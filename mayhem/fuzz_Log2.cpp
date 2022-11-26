#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

namespace TMath {
extern double Log2(double x);
}
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
   FuzzedDataProvider provider(data, size);
   double x = provider.ConsumeFloatingPoint<double>();
   TMath::Log2(x);
   return 0;
}