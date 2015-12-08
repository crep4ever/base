#include <unistd.h>
#include <sstream>

#include "logger.hh"
#include "benchmark.hh"
#include "configuration.hh"
#include "error.hh"

void log()
{
  for (int i = 0; i < 3; ++i)
  {
    LOG_DEBUG("Hello debug %d", i);
  }

  LOG_INFO("Hello info %d", 42);
  LOG_ERROR("Hello error %f", 42.0);
}

void error()
{
  CError e = ERROR(ERROR_BAD_IO);
  e.addInfo("This is a really bad error %d", 52);
  e.addInfo("Really really bad");
  LOG_ERROR("%s", e.toString().c_str());
}

void configuration()
{
  const int a = GET_CONF_VALUE(int, AlgoCalibrationDetectionMinTreshold);
  LOG_DEBUG("Read value [%d] ", a);

  const CParameter p = GET_CONF_PARAM(AlgoCalibrationDetectionMinThreshold);
  LOG_DEBUG("Read param [%s] ", p.toString().c_str());
}

void benchmark()
{
  CScopedBenchmark bench("hello_world");

  for (int i = 0; i < 2; ++i)
  {
    std::stringstream step;
    step << "iteration_" << i;
    bench.addStep(step.str());
    sleep(1);
  }
}

int main (void)
{
  CLogger::file("../data/example1.log");
  CBenchmark::file("../data/example1.csv");
  CConfiguration::file("../data/conf.xml");

  log();
  error();
  configuration();
  benchmark();

  return 0;
}
