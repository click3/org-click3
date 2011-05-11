
//外部ライブラリーの警告は無効化しておく
#pragma warning(push)
#pragma warning(disable: 4061) // case定義されていない列挙子があります
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4180) // 関数ポインターに対して無効な装飾子を使用しています
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4201) // 非標準の拡張機能、無名の構造体/共用体を使用しています
#pragma warning(disable: 4263) // 仮想関数をオーバーライドしていますが、引数の型が違います
#pragma warning(disable: 4264) // 引数の型のみ違う同名関数が定義されたため、仮想関数にはアクセスできなくなります
#pragma warning(disable: 4266) // 仮想関数のすべてのオーバーロードをオーバーライドしていません
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4365) // signed/unsignedが違う型変換が行われました
#pragma warning(disable: 4512) // 代入演算子を生成するために必要なコンストラクタがアクセスできません、代入演算子を作れませんでした
#pragma warning(disable: 4548) // 無効なカンマ式
#pragma warning(disable: 4555) // 副作用のない式
#pragma warning(disable: 4611) // 環境により動作が異なる可能性のある機能が使用されています
#pragma warning(disable: 4619) // 無効化を試みた警告番号は存在しません
#pragma warning(disable: 4625) // 基本クラスのコピーコンストラクタがアクセス不能なのでコピーコンストラクタが作れませんでした
#pragma warning(disable: 4626) // 基本クラスの代入演算子がアクセス不能なので代入演算子が作れませんでした
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4668) // 定義されていないシンボルが#if/#elifで使用されました
#pragma warning(disable: 4738) // 浮動小数点の計算結果を32bitに格納しているためパフォーマンスが低下しています
#pragma warning(disable: 4820) // 構造体のパッティングが発生しました
#pragma warning(disable: 4986) // 詳細不明
#pragma warning(disable: 4996) // セキュリティーホールになりうる標準C関数が使用されています

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
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
//外部ライブラリーの警告無効ここまで


#pragma warning(disable: 4061) // case定義されていない列挙子があります
#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4503) // 装飾名が4096文字を超えたため切り捨てられます
#pragma warning(disable: 4514) // 使用されていない関数/メソッドが削除されました
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4710) // インライン関数として選択されましたがインライン展開できませんでした

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
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
		boost::program_options::options_description opt("オプション");
		opt.add_options()
			("help,h",									"ヘルプを表示")
			("show-libraries",								"ビルド対象プロジェクトの一覧を表示")
			("show-properties",								"選択可能なビルドオプションの一覧を表示")
			("with",		value<std::string>(),				"ビルド対象プロジェクトを指定")
			("property",		value<std::string>(),				"ビルドオプションを指定")
			("filename,f",	value<std::string>()->default_value("make.ini"),	"使用する設定ファイルを指定");

		boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(opt).run(), opt_list);
		boost::program_options::notify(opt_list);

		if(opt_list.count("help")) {
			std::cout << opt << std::endl;
			return 0;
		}
	} catch(std::exception& ex) {
		std::cout << "コマンドライン引数の指定に誤りがあります: " << ex.what() << std::endl;
		return 1;
	}

	const std::string ini_name = opt_list["filename"].as<std::string>();
	LibMaker lib_maker(ini_name.c_str());
	
	std::vector<std::string> list;
	if(opt_list.count("show-properties") == 1) {
		if(!lib_maker.GetPropertyNameList(list) || list.empty()) {
			std::cout << "内部エラーが発生しました" << std::endl;
			return 1;
		}
		std::cout << "ビルドオプションの一覧:" << std::endl;
	} else if(opt_list.count("show-libraries") == 1) {
		if(!lib_maker.GetLibraryNameList(list) || list.empty()) {
			std::cout << "内部エラーが発生しました" << std::endl;
			return 1;
		}
		std::cout << "ビルド対象プロジェクトの一覧:" << std::endl;
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
