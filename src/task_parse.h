#ifndef _TASK_PARSE_H_
#define _TASK_PARSE_H_

#include <string>
#include <boost/smart_ptr.hpp>

typedef enum {
	TASK_INVALID = 0,
	TASK_ONE = 1,
	TASK_TWO = 2,
}TaskID;

class Task {
public:
    Task(int task_id):task_id(task_id) {}
    virtual ~Task() {}

    virtual bool Parse() = 0;

public:
	std::string t_json;
	int task_id;	
};

boost::shared_ptr<Task> NewTask(const char *json);

class TaskInvalid:public Task {
public:
	TaskInvalid();
	bool Parse();

public:
	unsigned int t_code;
	std::string t_error;
};

class TaskOne:public Task {
public:
	TaskOne();
	~TaskOne();

	bool Parse();

public:
	std::string t_file_path;
};

#endif




