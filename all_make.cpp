
//�O�����C�u�����[�̌x���͖��������Ă���
#pragma warning(push)
#pragma warning(disable: 4061) // case��`����Ă��Ȃ��񋓎q������܂�
#pragma warning(disable: 4100) // �錾���ꂽ�������g�p���Ă��܂���
#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4180) // �֐��|�C���^�[�ɑ΂��Ė����ȑ����q���g�p���Ă��܂�
#pragma warning(disable: 4189) // �ϐ��ɑ����Q�Ƃ���Ă��܂���
#pragma warning(disable: 4201) // ��W���̊g���@�\�A�����̍\����/���p�̂��g�p���Ă��܂�
#pragma warning(disable: 4263) // ���z�֐����I�[�o�[���C�h���Ă��܂����A�����̌^���Ⴂ�܂�
#pragma warning(disable: 4264) // �����̌^�݈̂Ⴄ�����֐�����`���ꂽ���߁A���z�֐��ɂ̓A�N�Z�X�ł��Ȃ��Ȃ�܂�
#pragma warning(disable: 4266) // ���z�֐��̂��ׂẴI�[�o�[���[�h���I�[�o�[���C�h���Ă��܂���
#pragma warning(disable: 4350) // const�Ȃ��̎Q�Ɠn���̓��e�������󂯎�邱�Ƃ��ł��Ȃ����߁A�ʂ̃R���X�g���N�^���Ă΂�܂�
#pragma warning(disable: 4365) // signed/unsigned���Ⴄ�^�ϊ����s���܂���
#pragma warning(disable: 4512) // ������Z�q�𐶐����邽�߂ɕK�v�ȃR���X�g���N�^���A�N�Z�X�ł��܂���A������Z�q�����܂���ł���
#pragma warning(disable: 4548) // �����ȃJ���}��
#pragma warning(disable: 4555) // ����p�̂Ȃ���
#pragma warning(disable: 4611) // ���ɂ�蓮�삪�قȂ�\���̂���@�\���g�p����Ă��܂�
#pragma warning(disable: 4619) // �����������݂��x���ԍ��͑��݂��܂���
#pragma warning(disable: 4625) // ��{�N���X�̃R�s�[�R���X�g���N�^���A�N�Z�X�s�\�Ȃ̂ŃR�s�[�R���X�g���N�^�����܂���ł���
#pragma warning(disable: 4626) // ��{�N���X�̑�����Z�q���A�N�Z�X�s�\�Ȃ̂ő�����Z�q�����܂���ł���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4668) // ��`����Ă��Ȃ��V���{����#if/#elif�Ŏg�p����܂���
#pragma warning(disable: 4738) // ���������_�̌v�Z���ʂ�32bit�Ɋi�[���Ă��邽�߃p�t�H�[�}���X���ቺ���Ă��܂�
#pragma warning(disable: 4820) // �\���̂̃p�b�e�B���O���������܂���
#pragma warning(disable: 4986) // �ڍוs��
#pragma warning(disable: 4996) // �Z�L�����e�B�[�z�[���ɂȂ肤��W��C�֐����g�p����Ă��܂�

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
#endif

#include <stdio.h>

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "boost/assign.hpp"
#include "boost/assert.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"
#include "boost/foreach.hpp"
#include "boost/tokenizer.hpp"
#include "boost/algorithm/string/replace.hpp"
#include "boost/algorithm/string/case_conv.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/filesystem/convenience.hpp"
#include "boost/program_options.hpp"
#include "boost/lambda/lambda.hpp"

#pragma warning(pop)
//�O�����C�u�����[�̌x�����������܂�


#pragma warning(disable: 4061) // case��`����Ă��Ȃ��񋓎q������܂�
#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4350) // const�Ȃ��̎Q�Ɠn���̓��e�������󂯎�邱�Ƃ��ł��Ȃ����߁A�ʂ̃R���X�g���N�^���Ă΂�܂�
#pragma warning(disable: 4503) // ��������4096�����𒴂������ߐ؂�̂Ă��܂�
#pragma warning(disable: 4514) // �g�p����Ă��Ȃ��֐�/���\�b�h���폜����܂���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4710) // �C�����C���֐��Ƃ��đI������܂������C�����C���W�J�ł��܂���ł���

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4100) // �錾���ꂽ�������g�p���Ă��܂���
#pragma warning(disable: 4189) // �ϐ��ɑ����Q�Ƃ���Ă��܂���
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
#endif

void print_tab(unsigned int tab) {
	for(unsigned int i = 0; i < tab; i++) {
		std::cout << "\t";
	}
}

void print_tree(const boost::property_tree::ptree &tree, unsigned int tab = 0) {
	BOOST_FOREACH(const boost::property_tree::ptree::value_type &child, tree) {
		print_tab(tab);
		if(child.second.data().empty()) {
			std::cout << "[" << child.first << "]" << std::endl;
			print_tree(child.second, tab+1);
		} else {
			std::cout << child.first << "=" << child.second.data() << std::endl;
		}
	}
}

class LibMaker {
protected:
	class Project {
	public:
		Project(const std::string &name, const std::vector<std::string> &src_files, const std::string &out_path) : name(name), src_files(src_files), out_path(out_path) { }
		void Print(unsigned int tab = 0) const {
			print_tab(tab);
			std::cout << "name: " << name << std::endl;
			print_tab(tab);
			std::cout << "src_files: " << std::endl;
			BOOST_FOREACH(const std::string &src_file, src_files) {
				print_tab(tab + 1);
				std::cout << src_file << std::endl;
			}
			print_tab(tab);
			std::cout << "out_path: " << out_path << std::endl;
		}
		const std::string &GetOutPath() const {
			return out_path;
		}
		std::string GetOutPath(const std::map<std::string, std::string> params) const {
			typedef std::map<std::string, std::string>::value_type map_pair;
			std::string result(out_path);
			BOOST_FOREACH(const map_pair &param, params) {
				const std::string key = "%" + boost::algorithm::to_upper_copy(param.first) + "%";
				const std::string &value = param.second;
				boost::algorithm::replace_all(result, key, value);
			}
			return result;
		}
		const std::string name;
		const std::vector<std::string> src_files;
	protected:
		const std::string out_path;
	};
	class Option {
	public:
		Option(const std::string options) : options(options) { }
		const std::string &Get(void) const {
			return options;
		}
		std::string Get(const std::map<std::string, std::string> params) const {
			typedef std::map<std::string, std::string>::value_type map_pair;
			std::string result(options);
			BOOST_FOREACH(const map_pair &param, params) {
				const std::string key = "%" + boost::algorithm::to_upper_copy(param.first) + "%";
				const std::string &value = param.second;
				boost::algorithm::replace_all(result, key, value);
			}
			return result;
		}
	protected:
		std::string options;
	};
public:
	LibMaker(const char *ini_filename) {
		const char *section_name[] = {"make_options", "compile_options", "lib_options"};

		boost::property_tree::ptree ini;
		read_ini(ini_filename, ini);

		const boost::property_tree::ptree &make_options = ini.get_child(section_name[0]);
		BOOST_ASSERT(make_options.size() == 2);
		compiler = make_options.get<std::string>("compiler");
		BOOST_ASSERT(!compiler.empty());
		lib_archiver = make_options.get<std::string>("lib_archiver");
		BOOST_ASSERT(!lib_archiver.empty());

		const boost::property_tree::ptree &compile_options = ini.get_child(section_name[1]);
		BOOST_ASSERT(compile_options.size() > 0);
		BOOST_FOREACH(const boost::property_tree::ptree::value_type &opt_pair, compile_options) {
			this->compile_options.insert(std::map<std::string, Option>::value_type(opt_pair.first, Option(opt_pair.second.data())));
		}
		BOOST_ASSERT(compile_options.size() == this->compile_options.size());

		const boost::property_tree::ptree &lib_options = ini.get_child(section_name[2]);
		BOOST_ASSERT(lib_options.size() > 0);
		BOOST_FOREACH(const boost::property_tree::ptree::value_type &opt_pair, lib_options) {
			BOOST_ASSERT(this->compile_options.count(opt_pair.first) == 1);
			this->lib_options.insert(std::map<std::string, Option>::value_type(opt_pair.first, Option(opt_pair.second.data())));
		}
		BOOST_ASSERT(lib_options.size() == this->lib_options.size());
		BOOST_ASSERT(this->compile_options.size() == this->lib_options.size());

		BOOST_FOREACH(const boost::property_tree::ptree::value_type &child_proj, ini) {
			if(child_proj.first == section_name[0] || child_proj.first == section_name[1] || child_proj.first == section_name[2]) {
				continue;
			}

			const std::string &proj_name = child_proj.first;
			BOOST_ASSERT(!proj_name.empty());

			const boost::property_tree::ptree &proj_tree = child_proj.second;
			BOOST_ASSERT(proj_tree.size() == 2);

			std::vector<std::string> src_files;
			const std::string &src_files_string = proj_tree.get<std::string>("src_files");
			boost::escaped_list_separator<char> sep('\\', ' ', '\"');
			boost::tokenizer<boost::escaped_list_separator<char> > src_file_tokens(src_files_string, sep);
			BOOST_FOREACH(const std::string &src_file, src_file_tokens) {
				src_files.push_back(src_file);
			}
			BOOST_ASSERT(!src_files.empty());

			const std::string &out_path = proj_tree.get<std::string>("out_path");
			BOOST_ASSERT(!out_path.empty());

			project_list.push_back(Project(proj_name, src_files, out_path));
		}
	}

	void Print(unsigned int tab = 0) {
		print_tab(tab);
		std::cout << "copmiler: " << compiler << std::endl;
		print_tab(tab);
		std::cout << "lib_archiver: " << lib_archiver << std::endl;
		print_tab(tab);
		std::cout << "compile_options:" << std::endl;
		typedef std::map<std::string, Option>::value_type map_pair;
		BOOST_FOREACH(const map_pair &options, compile_options) {
			print_tab(tab + 1);
			std::cout << options.first << ": " << options.second.Get() << std::endl;
		}
		print_tab(tab);
		std::cout << "lib_options:" << std::endl;
		BOOST_FOREACH(const map_pair &options, lib_options) {
			print_tab(tab + 1);
			std::cout << options.first << ": " << options.second.Get() << std::endl;
		}
		print_tab(tab);
		std::cout << "project_list:" << std::endl;
		BOOST_FOREACH(const Project &proj, project_list) {
			proj.Print(tab + 1);
		}
	}

	bool Run(const Project &proj, const std::string &option_name) const {
		const boost::filesystem::path temp_dir = boost::filesystem::temp_directory_path();
		std::vector<std::string> obj_path_list;
		BOOST_FOREACH(const std::string &src_file, proj.src_files) {
			const boost::filesystem::path src_path(src_file);
			const boost::filesystem::path out_dir = temp_dir/boost::filesystem::unique_path();
			boost::filesystem::create_directories(out_dir);
			const boost::filesystem::path obj_path = (out_dir/src_path.filename()).replace_extension(".obj");
			const std::map<std::string, std::string> compile_params = boost::assign::map_list_of("out_path", obj_path.string());
			const std::string command = compiler + " " + compile_options.find(option_name)->second.Get(compile_params) + " " + src_path.string();
			if(0 != ::system(command.c_str())) {
				return false;
			}
			obj_path_list.push_back(obj_path.string());
		}

		const std::map<std::string, std::string> out_path_params = boost::assign::map_list_of("compile_type", option_name);
		const boost::filesystem::path out_path = proj.GetOutPath(out_path_params);
		const boost::filesystem::path out_dir = boost::filesystem::path(out_path).remove_filename();
		boost::filesystem::create_directories(out_dir);
		const std::map<std::string, std::string> lib_params = boost::assign::map_list_of("out_path", out_path.string());
		std::string command = lib_archiver + " " + lib_options.find(option_name)->second.Get(lib_params);
		BOOST_FOREACH(const std::string &obj_path, obj_path_list) {
			command.append(" " + obj_path);
		}
		if(0 != ::system(command.c_str())) {
			return false;
		}
		return true;
	}
	bool RunAllProject(const std::string &option_name) const {
		BOOST_FOREACH(const Project &proj, project_list) {
			if(!Run(proj, option_name)) {
				return false;
			}
		}
		return true;
	}
	bool RunAllOption(const Project &proj) const {
		typedef std::map<std::string, Option>::value_type map_pair;
		BOOST_FOREACH(const map_pair &option, compile_options) {
			if(!Run(proj, option.first)) {
				return false;
			}
		}
		return true;
	}
	bool RunAll(void) const {
		BOOST_FOREACH(const Project &proj, project_list) {
			if(!RunAllOption(proj)) {
				return false;
			}
		}
		return true;
	}
	bool Run(const std::string &proj_name = std::string(), const std::string &option_name = std::string()) const {
		if(proj_name.empty() && option_name.empty()) {
			return RunAll();
		}
		if(proj_name.empty()) {
			return RunAllProject(option_name);
		}
		struct FindProjectName {
			FindProjectName(const std::string &name) : name(name) { }
			const std::string name;
			bool operator()(const Project &proj) const {
				return proj.name == name;
			}
		};
		const std::vector<Project>::const_iterator it = std::find_if(project_list.begin(), project_list.end(), FindProjectName(proj_name));
		if(it == project_list.end()) {
			return false;
		}
		const Project &proj = *it;
		if(option_name.empty()) {
			return RunAllOption(proj);
		}
		return Run(proj, option_name);
	}
	bool GetPropertyNameList(std::vector<std::string> &result) {
		result.clear();
		struct TransformMapKey {
			std::string operator()(const std::map<std::string, Option>::value_type &map_pair) const {
				return map_pair.first;
			}
		};
		std::transform(compile_options.begin(), compile_options.end(), std::back_inserter(result), TransformMapKey());
		return true;
	}
	bool GetLibraryNameList(std::vector<std::string> &result) {
		result.clear();
		struct TransformProjectName {
			std::string operator()(const Project &proj) const {
				return proj.name;
			}
		};
		std::transform(project_list.begin(), project_list.end(), std::back_inserter(result), TransformProjectName());
		return true;
	}
protected:
	std::string compiler;
	std::string lib_archiver;
	std::map<std::string, Option> compile_options;
	std::map<std::string, Option> lib_options;
	std::vector<Project> project_list;
};

int main(unsigned int argc, const char * const argv[]) {
	boost::program_options::variables_map opt_list;
	try {
		using boost::program_options::value;
		boost::program_options::options_description opt("�I�v�V����");
		opt.add_options()
			("help,h",									"�w���v��\��")
			("show-libraries",								"�r���h�Ώۃv���W�F�N�g�̈ꗗ��\��")
			("show-properties",								"�I���\�ȃr���h�I�v�V�����̈ꗗ��\��")
			("with",		value<std::string>(),				"�r���h�Ώۃv���W�F�N�g���w��")
			("property",		value<std::string>(),				"�r���h�I�v�V�������w��")
			("filename,f",	value<std::string>()->default_value("make.ini"),	"�g�p����ݒ�t�@�C�����w��");

		boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(opt).run(), opt_list);
		boost::program_options::notify(opt_list);

		if(opt_list.count("help")) {
			std::cout << opt << std::endl;
			return 0;
		}
	} catch(std::exception& ex) {
		std::cout << "�R�}���h���C�������̎w��Ɍ�肪����܂�: " << ex.what() << std::endl;
		return 1;
	}

	const std::string ini_name = opt_list["filename"].as<std::string>();
	LibMaker lib_maker(ini_name.c_str());
	
	std::vector<std::string> list;
	if(opt_list.count("show-properties") == 1) {
		if(!lib_maker.GetPropertyNameList(list) || list.empty()) {
			std::cout << "�����G���[���������܂���" << std::endl;
			return 1;
		}
		std::cout << "�r���h�I�v�V�����̈ꗗ:" << std::endl;
	} else if(opt_list.count("show-libraries") == 1) {
		if(!lib_maker.GetLibraryNameList(list) || list.empty()) {
			std::cout << "�����G���[���������܂���" << std::endl;
			return 1;
		}
		std::cout << "�r���h�Ώۃv���W�F�N�g�̈ꗗ:" << std::endl;
	}
	if(!list.empty()) {
		BOOST_FOREACH(const std::string &name, list) {
			std::cout << "   - " << name << std::endl;
		}
		return 0;
	}

	std::string proj_name;
	if(opt_list.count("with") == 1) {
		proj_name = opt_list["with"].as<std::string>();
	}
	std::string option_name;
	if(opt_list.count("property") == 1) {
		option_name = opt_list["property"].as<std::string>();
	}
	if(!lib_maker.Run(proj_name, option_name)) {
		return 1;
	}
	return 0;
}
