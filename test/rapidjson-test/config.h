#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

class Config {
public:
    ~Config();

	static Config *getInstance();
	
    bool load(std::string path="./config.json");
    void writejsonfile();
    std::string json();
protected:
    template <typename PrettyWriter>
    void serialize(PrettyWriter &writer) const;

public:
    std::string m_path;

    std::string version;
    std::string m_mq_host;
    std::string m_mq_uname;
    std::string m_mq_upwd;

	std::string m_file_storage_path;
	std::string m_alg_img_dir_name;
    std::string m_mq_que_name_in;
    std::string m_mq_que_name_out;
    std::string m_mq_que_name_proc_info;
    std::string m_mq_que_name_opt;
	std::string m_mq_que_name_pics;
	std::string m_mq_que_name_feature;
	std::string m_mq_que_name_nvr;
    std::string nvr_url_device_states;
    std::string nvr_url_device_healthes;
    std::string nvr_url_device_videodownload;
    std::string nvr_url_device_videopath;
	float m_fThresh;
	int min_width;
	int min_height;

private:
	Config();

	static Config *instance;
};

#endif
