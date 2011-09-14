#ifndef HEATWAVE_JOB_SYSTEM_JOBMANAGER_HPP
#define HEATWAVE_JOB_SYSTEM_JOBMANAGER_HPP

namespace hw {
namespace job_system {

typedef void (*JobFunction)(void);
typedef int job_id;

struct JobInfo;

JobInfo dispatchJob(JobFunction job, void* data);
void waitOn(JobInfo* dependency);

} //namespace job_system
} //namespace hw

#endif