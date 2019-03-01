#include <iostream>
#include <boost/shared_ptr.hpp>
#include "config.h"

using namespace std;

int main()
{
	//boost::shared_ptr<Config> conf = (boost::shared_ptr<Config>)Config::getInstance();
	Config *conf = Config::getInstance();
	cout << "conf->m_path = " << conf->m_path << endl;
	cout << "conf->version = " << conf->version << endl;
	cout << "conf->m_mq_host = " << conf->m_mq_host << endl;
	cout << "conf->m_mq_uname = " << conf->m_mq_uname << endl;
	cout << "conf->m_mq_upwd = " << conf->m_mq_upwd << endl;	

	return 0;
}
