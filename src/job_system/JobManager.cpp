#include "JobManager.hpp"

namespace hw { 
namespace job_system {

struct JobInfo
{
   job_id id; //index on job_pool
   void* data;
   JobFunction job_func;
};

struct JobPool
{
   static const int MAX_JOBS = 32;
   int num_jobs;
   JobInfo jobs[MAX_JOBS];
};


JobPool g_jobPool;

JobInfo dispatchJob(JobFunction job, void* data)
{
   return JobInfo();
}

void waitOn(JobInfo* dependency)
{
}

}
}