class Job:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def comp(self, job):
        return self.start >= job.end
        
class Jobs:

    def __init__(self):
        self.jobs = []

    def add_job_by_time(self, start, end):
        self.jobs.append(Job(start, end))

    def add_job(self, job):
        self.jobs.append(job)

    def sort_job(self):
        self.jobs = sorted(self.jobs, key=lambda x: x.end)

    def algorithm(self):
        self.sort_job()
        schedule = Jobs()
        schedule.add_job(self.jobs[0])
        last = self.jobs[0]
        for i in self.jobs:
            if i.comp(last):
                schedule.add_job(i)
                last = i
        return schedule

    def print_jobs(self):
        for i in self.jobs:
            print(f"({i.start}, {i.end}), ", end = " ")
        print()

import random as rn
i = 0
jobs = Jobs()
while i < 10:
    start = rn.randint(0, 24)
    end = rn.randint(0, 24)
    if start >= end:
        start, end = end, start
    jobs.add_job_by_time(start, end)
    i += 1

schedule = jobs.algorithm()
jobs.print_jobs()
schedule.print_jobs()
    
    



            



        


