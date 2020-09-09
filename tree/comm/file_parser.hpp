#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <string>
#include <vector>

namespace file_parser
{
class FileParser
{
	public:
		FileParser(const std::string &filename)
			: m_filename(filename),
			m_content("")
		{
			read_file();
		}

		void parse_content(std::vector<std::string> &word_vec)
		{
			int start_index = 0;
			int end_index = -1;
			while(true)
			{
				start_index = end_index + 1;
				get_first_character(&start_index);		
				if(start_index == m_content.length())
					break;
				end_index = start_index + 1;
				get_first_not_character(&end_index);
				std::string word = m_content.substr(start_index, end_index-start_index);
				word_vec.push_back(word);
				if(end_index == m_content.length())
					break;
			}
		}

	private:
		void read_file()
		{
			std::string line;
			std::ifstream ifs;
			ifs.open("a.txt");
			if(ifs.is_open())
			{
				while(getline(ifs, line))
					m_content += line;
			}
			ifs.close();
		}

		void get_first_character(int *iStart)
		{
			while(*iStart < m_content.length() && !isalpha(m_content.at(*iStart)))
				(*iStart)++;
		}

		void get_first_not_character(int *iEnd)
		{
			while(*iEnd < m_content.length() && isalpha(m_content.at(*iEnd)))
				(*iEnd)++;
		}

		std::string m_filename;		
		std::string m_content;
};
}
#endif

#if 0
int main()
{
	std::vector<std::string> word_vec;
	FileParser file_parser("a.txt");
	file_parser.parse_content(word_vec);
	for(auto & word : word_vec)
		std::cout << word << "\n";

	return 0;
}
#endif
