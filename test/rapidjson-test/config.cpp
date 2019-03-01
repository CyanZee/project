//#include <zlog.h>
#include <fstream>
//#include <rapidjson/document.h>
//#include <rapidjson/prettywriter.h>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include <iostream>
#include "config.h"

using namespace std;
using namespace rapidjson;

Config *Config::instance = 0;

Config *Config::getInstance()
{
	if(!instance)
	{
		instance = new Config();
	}
	return instance;
}

Config::Config()
{
	load();
/*
	version = "unkown";    	
    m_mq_host = "unkown";
  	m_mq_uname = "unkown";
    m_mq_upwd = "unkown";
    m_mq_que_name_in = "unkown";
    m_mq_que_name_out = "unkown";
	m_mq_que_name_proc_info = "unkown";
	m_file_storage_path = "unkonwn";
	m_alg_img_dir_name = "unkonwn";
	m_mq_que_name_opt = "unkown";
	m_mq_que_name_pics = "unkown";
	m_mq_que_name_feature = "unkown";
	m_mq_que_name_nvr = "unkown";
    nvr_url_device_states = "unkown";
    nvr_url_device_healthes = "unkown";
    nvr_url_device_videodownload = "unkown";
    nvr_url_device_videopath = "unkown";
	m_fThresh = 0.5;
	min_width = 50;
	min_height = 50;
*/
}

Config::~Config() {
	if(instance)
	{
		delete instance;
		instance = NULL;
	}
}
void Config::writejsonfile()
{
	std::string jsondata;
	long size;
	jsondata = json();
	ofstream file(m_path, ios::out|ios::binary|ios::trunc);
	size = jsondata.size();
	file.write(jsondata.c_str(),size);
	file.close();
	//dzlog_debug("+++ config.json writejsonfile() success.");
}
std::string readjsonfile(const char * jsonfile)
{
	std::ifstream fin;
	std::string jsondata = " ";
	fin.open(jsonfile,std::ifstream::in);
	if (!fin.is_open())
	{
		//dzlog_error("--- read json file error.");
	}
	std::string line;
	while (getline(fin,line)) {
		jsondata.append(line + "\n");
	}
	return jsondata;
}

bool Config::load(std::string path) {
	
	std::string json;
	json = readjsonfile((char *)path.c_str());
	m_path = path;
	
	Document doc;

	doc.Parse(json.c_str());
	if (doc.IsObject())
	{
		if (doc.HasMember("version"))
		{
			if (doc["version"].IsString())
			{
				version = doc["version"].GetString();
			}
		}
		if (doc.HasMember("m_mq_host"))
		{
			if (doc["m_mq_host"].IsString())
			{
				m_mq_host = doc["m_mq_host"].GetString();
			}
		}
		if (doc.HasMember("m_mq_uname"))
		{
			if (doc["m_mq_uname"].IsString())
			{
				m_mq_uname = doc["m_mq_uname"].GetString();
			}
		}
		if (doc.HasMember("m_mq_upwd"))
		{
			if (doc["m_mq_upwd"].IsString())
			{
				m_mq_upwd = doc["m_mq_upwd"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_proc_info"))
		{
			if (doc["m_mq_que_name_proc_info"].IsString())
			{
				m_mq_que_name_proc_info = doc["m_mq_que_name_proc_info"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_opt"))
		{
			if (doc["m_mq_que_name_opt"].IsString())
			{
				m_mq_que_name_opt = doc["m_mq_que_name_opt"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_pics_info"))
		{
			if (doc["m_mq_que_name_pics_info"].IsString())
			{
				m_mq_que_name_pics = doc["m_mq_que_name_pics_info"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_feature_info"))
		{
			if (doc["m_mq_que_name_feature_info"].IsString())
			{
				m_mq_que_name_feature = doc["m_mq_que_name_feature_info"].GetString();
			}
		}
		if (doc.HasMember("m_file_storage_path"))
		{
			if (doc["m_file_storage_path"].IsString())
			{
				m_file_storage_path = doc["m_file_storage_path"].GetString();
			}
		}	
		if (doc.HasMember("m_alg_img_dir_name"))
		{
			if (doc["m_alg_img_dir_name"].IsString())
			{
				m_alg_img_dir_name = doc["m_alg_img_dir_name"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_in"))
		{
			if (doc["m_mq_que_name_in"].IsString())
			{
				m_mq_que_name_in = doc["m_mq_que_name_in"].GetString();
			}
		}
		if (doc.HasMember("m_mq_que_name_out"))
		{
			if (doc["m_mq_que_name_out"].IsString())
			{
				m_mq_que_name_out = doc["m_mq_que_name_out"].GetString();
			}
		}
		
		if (doc.HasMember("m_mq_que_name_nvr"))
		{
			if (doc["m_mq_que_name_nvr"].IsString())
			{
				m_mq_que_name_nvr = doc["m_mq_que_name_nvr"].GetString();
			}
		}
		if (doc.HasMember("nvr_url_device_states"))
		{
			if (doc["nvr_url_device_states"].IsString())
			{
				nvr_url_device_states = doc["nvr_url_device_states"].GetString();
			}
		}
		if (doc.HasMember("nvr_url_device_healthes"))
		{
			if (doc["nvr_url_device_healthes"].IsString())
			{
				nvr_url_device_healthes = doc["nvr_url_device_healthes"].GetString();
			}
		}
		if (doc.HasMember("nvr_url_device_videodownload"))
		{
			if (doc["nvr_url_device_videodownload"].IsString())
			{
				nvr_url_device_videodownload = doc["nvr_url_device_videodownload"].GetString();
			}
		}
		if (doc.HasMember("nvr_url_device_videopath"))
		{
			if (doc["nvr_url_device_videopath"].IsString())
			{
				nvr_url_device_videopath = doc["nvr_url_device_videopath"].GetString();
			}
		}
		if (doc.HasMember("m_fThresh"))
		{
			if (doc["m_fThresh"].IsFloat())
			{
				m_fThresh = doc["m_fThresh"].GetFloat();
			}
		}
		if (doc.HasMember("min_width"))
		{
			if (doc["min_width"].IsUint())
			{
				min_width = doc["min_width"].GetUint();
			}
		}
		if (doc.HasMember("min_height"))
		{
			if (doc["min_height"].IsUint())
			{
				min_height = doc["min_height"].GetUint();
			}
		}
	}
	else
	{
		//dzlog_error("---There is nonstandard jsondata.");
		
	}
	
	#if 0
	dzlog_debug("config: %s", m_path.c_str());
	dzlog_debug("version: %s", version.c_str());
    dzlog_debug("m_mq_host: %s", m_mq_host.c_str());
    dzlog_debug("m_mq_uname: %s", m_mq_uname.c_str());
    dzlog_debug("m_mq_upwd: %s", m_mq_upwd.c_str());
    dzlog_debug("m_file_storage_path: %s", m_file_storage_path.c_str());
    dzlog_debug("m_alg_img_dir_name: %s", m_alg_img_dir_name.c_str());
    dzlog_debug("m_mq_que_name_in: %s", m_mq_que_name_in.c_str());
    dzlog_debug("m_mq_que_name_out: %s", m_mq_que_name_out.c_str());
    dzlog_debug("m_mq_que_name_proc_info: %s", m_mq_que_name_proc_info.c_str());
    dzlog_debug("m_mq_que_name_opt: %s", m_mq_que_name_opt.c_str());
	dzlog_debug("m_mq_que_name_pics: %s", m_mq_que_name_pics.c_str());
	dzlog_debug("m_mq_que_name_feature: %s", m_mq_que_name_feature.c_str());
	dzlog_debug("m_mq_que_name_nvr: %s", m_mq_que_name_nvr.c_str());
	dzlog_debug("nvr_url_device_states: %s", nvr_url_device_states.c_str());
	dzlog_debug("nvr_url_device_healthes: %s", nvr_url_device_healthes.c_str());
	dzlog_debug("nvr_url_device_videodownload: %s", nvr_url_device_videodownload.c_str());
	dzlog_debug("nvr_url_device_videopath: %s", nvr_url_device_videopath.c_str());
	dzlog_debug("m_fThresh: %f", m_fThresh);
	dzlog_debug("min_width: %d", min_width);
	dzlog_debug("min_height: %d", min_height);
	#endif
    return true;
}
template <typename PrettyWriter>

void Config::serialize(PrettyWriter &writer) const {
	writer.StartObject();

	writer.Key("version");
	writer.String(version.c_str());

	writer.Key("m_mq_host");
	writer.String(m_mq_host.c_str());

	writer.Key("m_mq_uname");
	writer.String(m_mq_uname.c_str());

	writer.Key("m_mq_upwd");
	writer.String(m_mq_upwd.c_str());

	writer.Key("m_file_storage_path");
	writer.String(m_file_storage_path.c_str());

	writer.Key("m_alg_img_dir_name");
	writer.String(m_alg_img_dir_name.c_str());

	writer.Key("m_mq_que_name_in");
	writer.String(m_mq_que_name_in.c_str());

	writer.Key("m_mq_que_name_out");
	writer.String(m_mq_que_name_out.c_str());

	writer.Key("m_mq_que_name_opt");
	writer.String(m_mq_que_name_opt.c_str());

	writer.Key("m_mq_que_name_proc_info");
	writer.String(m_mq_que_name_proc_info.c_str());

	writer.Key("m_mq_que_name_pics_info");
	writer.String(m_mq_que_name_pics.c_str());

	writer.Key("m_mq_que_name_feature_info");
	writer.String(m_mq_que_name_feature.c_str());
	
	writer.Key("m_mq_que_name_nvr");
	writer.String(m_mq_que_name_nvr.c_str());

	writer.Key("nvr_url_device_states");
	writer.String(nvr_url_device_states.c_str());

	writer.Key("nvr_url_device_healthes");
	writer.String(nvr_url_device_healthes.c_str());

	writer.Key("nvr_url_device_videodownload");
	writer.String(nvr_url_device_videodownload.c_str());

	writer.Key("nvr_url_device_videopath");
	writer.String(nvr_url_device_videopath.c_str());

	writer.String("m_fThresh");
	writer.Double(m_fThresh);

	writer.String("min_width");
	writer.Uint(min_width);

	writer.String("min_height");
	writer.Uint(min_height);

	writer.EndObject();	
}

std::string Config::json() {
	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);
	serialize(writer);
	return sb.GetString();
}
