#ifndef IO_STREAM_H
#define IO_STREAM_H

    #include <fstream>
    #include <string>

    void execute_test_cases(void);

    void manage_query_stream_state(void);
    void access_condition_state(void);
    void refresh_ostream_buffer(void);
    void access_file_stream(void);
    void clear_file_stream_states(void);
    void access_stringstream_objects(void);
    void convert_format_sstream_objects(void);

    std::ifstream& open_file(std::ifstream& in, const std::string& file);

#endif  /* IO_STREAM_H */
