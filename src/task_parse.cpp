#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <iostream>
#include "task_parse.h"

using namespace rapidjson;

std::string readjsonfile(const char * jsonfile)
{
	std::ifstream fin;
	std::string jsondata = " ";
	fin.open(jsonfile,std::ifstream::in);
	if (!fin.is_open())
	{
		std::cout<< "--- read json file error." << std::endl;
	}
	std::string line;
	while (getline(fin,line)) {
		jsondata.append(line + "\n");
	}
	return jsondata;
}

boost::shared_ptr<Task> NewTask(const char *json) {
	Document doc;

	doc.Parse(json);

	if (doc.IsObject())
	{
		if (! doc.HasMember("task_id")) 
		{
			std::cout << "--- There is an invalid task: %s " << json << std::endl;
			TaskInvalid *task = new TaskInvalid();
			task->t_code = -1;
			task->t_error = "There is an invalid task.";

			return boost::shared_ptr<Task>(task);
		}

		int id = doc["task_id"].GetInt();

		switch (id) {
		case TASK_ONE:
		{
			std::cout << "+++ There is TASK_ONE task. " << std::endl;
			TaskOne *task = new TaskOne();
			task->t_json = json;
			task->Parse();
			
			return boost::shared_ptr<Task>(task);
		}
		case TASK_TWO:
		{
			std::cout << "+++ There is TASK_TWO task. " << std::endl;
			TaskInvalid *task = new TaskInvalid();
			return boost::shared_ptr<Task>(task);	
		}
		default:
		{
			std::cout << "--- There is an unknow task. " << std::endl;
			TaskInvalid *task = new TaskInvalid();
			task->t_code = -2;
			task->t_error = "There is an nonsupport task.";

			return boost::shared_ptr<Task>(task);
		}
		}
	}
	else
	{
		std::cout << "---There is nonstandard jsondata." << std::endl;
		TaskInvalid *task = new TaskInvalid();
		return boost::shared_ptr<Task>(task);
	}
}

TaskInvalid::TaskInvalid():Task(TASK_INVALID) {}

bool TaskInvalid::Parse() {
	return false;
}

TaskOne::TaskOne():Task(TASK_ONE) {}

TaskOne::~TaskOne() {}

bool TaskOne::Parse() {
	
	#if 0
		std::string json = "{\"m_mq_host\":\"localhost\",\"m_mq_uname\":\"admin\",\"m_mq_upwd\":\"123123\",\"m_mq_que_name_in\":\"task-queue\",\"m_mq_que_name_out\":\"ret-queue\"}";
	#endif
	
	//std::string json;
	//json = readjsonfile((char *)m_path.c_str());
	//std::cout << "+++ the jsondata is: " << json << std::endl;
	
	Document doc;

	doc.Parse(t_json.c_str());
	if (doc.IsObject())
	{
		if (doc.HasMember("t_file_path"))
		{
			if (doc["t_file_path"].IsString())
			{
				t_file_path = doc["t_file_path"].GetString();
			}
		}
	}
	
    return true;
}





