/* This file is automatically generated from wc-metadata.sql and /opt/svnrm-1.10/tempdir/subversion-1.10.6/subversion/libsvn_wc/token-map.h.
 * Do not edit this file -- edit the source and rerun gen-make.py */

#define STMT_CREATE_SCHEMA 0
#define STMT_0_INFO {"STMT_CREATE_SCHEMA", NULL}
#define STMT_0 \
  "CREATE TABLE REPOSITORY ( " \
  "  id INTEGER PRIMARY KEY AUTOINCREMENT, " \
  "  root  TEXT UNIQUE NOT NULL, " \
  "  uuid  TEXT NOT NULL " \
  "  ); " \
  "CREATE INDEX I_UUID ON REPOSITORY (uuid); " \
  "CREATE INDEX I_ROOT ON REPOSITORY (root); " \
  "CREATE TABLE WCROOT ( " \
  "  id  INTEGER PRIMARY KEY AUTOINCREMENT, " \
  "  local_abspath  TEXT UNIQUE " \
  "  ); " \
  "CREATE UNIQUE INDEX I_LOCAL_ABSPATH ON WCROOT (local_abspath); " \
  "CREATE TABLE PRISTINE ( " \
  "  checksum  TEXT NOT NULL PRIMARY KEY, " \
  "  compression  INTEGER, " \
  "  size  INTEGER NOT NULL, " \
  "  refcount  INTEGER NOT NULL, " \
  "  md5_checksum  TEXT NOT NULL " \
  "  ); " \
  "CREATE INDEX I_PRISTINE_MD5 ON PRISTINE (md5_checksum); " \
  "CREATE TABLE ACTUAL_NODE ( " \
  "  wc_id  INTEGER NOT NULL REFERENCES WCROOT (id), " \
  "  local_relpath  TEXT NOT NULL, " \
  "  parent_relpath  TEXT, " \
  "  properties  BLOB, " \
  "  conflict_old  TEXT, " \
  "  conflict_new  TEXT, " \
  "  conflict_working  TEXT, " \
  "  prop_reject  TEXT, " \
  "  changelist  TEXT, " \
  "  text_mod  TEXT, " \
  "  tree_conflict_data  TEXT, " \
  "  conflict_data  BLOB, " \
  "  older_checksum  TEXT REFERENCES PRISTINE (checksum), " \
  "  left_checksum  TEXT REFERENCES PRISTINE (checksum), " \
  "  right_checksum  TEXT REFERENCES PRISTINE (checksum), " \
  "  PRIMARY KEY (wc_id, local_relpath) " \
  "  ); " \
  "CREATE UNIQUE INDEX I_ACTUAL_PARENT ON ACTUAL_NODE (wc_id, parent_relpath, " \
  "                                                    local_relpath); " \
  "CREATE TABLE LOCK ( " \
  "  repos_id  INTEGER NOT NULL REFERENCES REPOSITORY (id), " \
  "  repos_relpath  TEXT NOT NULL, " \
  "  lock_token  TEXT NOT NULL, " \
  "  lock_owner  TEXT, " \
  "  lock_comment  TEXT, " \
  "  lock_date  INTEGER, " \
  "  PRIMARY KEY (repos_id, repos_relpath) " \
  "  ); " \
  "CREATE TABLE WORK_QUEUE ( " \
  "  id  INTEGER PRIMARY KEY AUTOINCREMENT, " \
  "  work  BLOB NOT NULL " \
  "  ); " \
  "CREATE TABLE WC_LOCK ( " \
  "  wc_id  INTEGER NOT NULL  REFERENCES WCROOT (id), " \
  "  local_dir_relpath  TEXT NOT NULL, " \
  "  locked_levels  INTEGER NOT NULL DEFAULT -1, " \
  "  PRIMARY KEY (wc_id, local_dir_relpath) " \
  " ); " \
  "CREATE TABLE NODES ( " \
  "  wc_id  INTEGER NOT NULL REFERENCES WCROOT (id), " \
  "  local_relpath  TEXT NOT NULL, " \
  "  op_depth INTEGER NOT NULL, " \
  "  parent_relpath  TEXT, " \
  "  repos_id  INTEGER REFERENCES REPOSITORY (id), " \
  "  repos_path  TEXT, " \
  "  revision  INTEGER, " \
  "  presence  TEXT NOT NULL, " \
  "  moved_here  INTEGER, " \
  "  moved_to  TEXT, " \
  "  kind  TEXT NOT NULL, " \
  "  properties  BLOB, " \
  "  depth  TEXT, " \
  "  checksum  TEXT REFERENCES PRISTINE (checksum), " \
  "  symlink_target  TEXT, " \
  "  changed_revision  INTEGER, " \
  "  changed_date      INTEGER, " \
  "  changed_author    TEXT, " \
  "  translated_size  INTEGER, " \
  "  last_mod_time  INTEGER, " \
  "  dav_cache  BLOB, " \
  "  file_external  INTEGER, " \
  "  inherited_props  BLOB, " \
  "  PRIMARY KEY (wc_id, local_relpath, op_depth) " \
  "  ); " \
  "CREATE UNIQUE INDEX I_NODES_PARENT ON NODES (wc_id, parent_relpath, " \
  "                                             local_relpath, op_depth); " \
  "CREATE UNIQUE INDEX I_NODES_MOVED ON NODES (wc_id, moved_to, op_depth); " \
  "CREATE VIEW NODES_CURRENT AS " \
  "  SELECT * FROM nodes AS n " \
  "    WHERE op_depth = (SELECT MAX(op_depth) FROM nodes AS n2 " \
  "                      WHERE n2.wc_id = n.wc_id " \
  "                        AND n2.local_relpath = n.local_relpath); " \
  "CREATE VIEW NODES_BASE AS " \
  "  SELECT * FROM nodes " \
  "  WHERE op_depth = 0; " \
  "CREATE TRIGGER nodes_insert_trigger " \
  "AFTER INSERT ON nodes " \
  "WHEN NEW.checksum IS NOT NULL " \
  "BEGIN " \
  "  UPDATE pristine SET refcount = refcount + 1 " \
  "  WHERE checksum = NEW.checksum; " \
  "END; " \
  "CREATE TRIGGER nodes_delete_trigger " \
  "AFTER DELETE ON nodes " \
  "WHEN OLD.checksum IS NOT NULL " \
  "BEGIN " \
  "  UPDATE pristine SET refcount = refcount - 1 " \
  "  WHERE checksum = OLD.checksum; " \
  "END; " \
  "CREATE TRIGGER nodes_update_checksum_trigger " \
  "AFTER UPDATE OF checksum ON nodes " \
  "WHEN NEW.checksum IS NOT OLD.checksum " \
  "BEGIN " \
  "  UPDATE pristine SET refcount = refcount + 1 " \
  "  WHERE checksum = NEW.checksum; " \
  "  UPDATE pristine SET refcount = refcount - 1 " \
  "  WHERE checksum = OLD.checksum; " \
  "END; " \
  "CREATE TABLE EXTERNALS ( " \
  "  wc_id  INTEGER NOT NULL REFERENCES WCROOT (id), " \
  "  local_relpath  TEXT NOT NULL, " \
  "  parent_relpath  TEXT NOT NULL, " \
  "  repos_id  INTEGER NOT NULL REFERENCES REPOSITORY (id), " \
  "  presence  TEXT NOT NULL, " \
  "  kind  TEXT NOT NULL, " \
  "  def_local_relpath         TEXT NOT NULL, " \
  "  def_repos_relpath         TEXT NOT NULL, " \
  "  def_operational_revision  TEXT, " \
  "  def_revision              TEXT, " \
  "  PRIMARY KEY (wc_id, local_relpath) " \
  "); " \
  "CREATE UNIQUE INDEX I_EXTERNALS_DEFINED ON EXTERNALS (wc_id, " \
  "                                                      def_local_relpath, " \
  "                                                      local_relpath); " \
  "PRAGMA user_version = " \
  APR_STRINGIFY(SVN_WC__VERSION) \
  "; " \
  ""

#define STMT_INSTALL_SCHEMA_STATISTICS 1
#define STMT_1_INFO {"STMT_INSTALL_SCHEMA_STATISTICS", NULL}
#define STMT_1 \
  "ANALYZE sqlite_master; " \
  "DELETE FROM sqlite_stat1 " \
  "WHERE tbl in ('NODES', 'ACTUAL_NODE', 'LOCK', 'WC_LOCK', 'EXTERNALS'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('NODES', 'sqlite_autoindex_NODES_1',               '8000 8000 2 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('NODES', 'I_NODES_PARENT',                         '8000 8000 10 2 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('NODES', 'I_NODES_MOVED',                          '8000 8000 1 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('ACTUAL_NODE', 'sqlite_autoindex_ACTUAL_NODE_1',   '8000 8000 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('ACTUAL_NODE', 'I_ACTUAL_PARENT',                  '8000 8000 10 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('LOCK', 'sqlite_autoindex_LOCK_1',                 '100 100 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('WC_LOCK', 'sqlite_autoindex_WC_LOCK_1',           '100 100 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('EXTERNALS','sqlite_autoindex_EXTERNALS_1',        '100 100 1'); " \
  "INSERT INTO sqlite_stat1(tbl, idx, stat) VALUES " \
  "    ('EXTERNALS','I_EXTERNALS_DEFINED',                 '100 100 3 1'); " \
  "ANALYZE sqlite_master; " \
  ""

#define STMT_UPGRADE_TO_30 2
#define STMT_2_INFO {"STMT_UPGRADE_TO_30", NULL}
#define STMT_2 \
  "CREATE UNIQUE INDEX IF NOT EXISTS I_NODES_MOVED " \
  "ON NODES (wc_id, moved_to, op_depth); " \
  "CREATE INDEX IF NOT EXISTS I_PRISTINE_MD5 ON PRISTINE (md5_checksum); " \
  "UPDATE nodes SET presence = \"server-excluded\" WHERE presence = \"absent\"; " \
  "UPDATE nodes SET file_external=1 WHERE file_external IS NOT NULL; " \
  ""

#define STMT_UPGRADE_30_SELECT_CONFLICT_SEPARATE 3
#define STMT_3_INFO {"STMT_UPGRADE_30_SELECT_CONFLICT_SEPARATE", NULL}
#define STMT_3 \
  "SELECT wc_id, local_relpath, " \
  "  conflict_old, conflict_working, conflict_new, prop_reject, tree_conflict_data " \
  "FROM actual_node " \
  "WHERE conflict_old IS NOT NULL " \
  "   OR conflict_working IS NOT NULL " \
  "   OR conflict_new IS NOT NULL " \
  "   OR prop_reject IS NOT NULL " \
  "   OR tree_conflict_data IS NOT NULL " \
  "ORDER by wc_id, local_relpath " \
  ""

#define STMT_UPGRADE_30_SET_CONFLICT 4
#define STMT_4_INFO {"STMT_UPGRADE_30_SET_CONFLICT", NULL}
#define STMT_4 \
  "UPDATE actual_node SET conflict_data = ?3, conflict_old = NULL, " \
  "  conflict_working = NULL, conflict_new = NULL, prop_reject = NULL, " \
  "  tree_conflict_data = NULL " \
  "WHERE wc_id = ?1 and local_relpath = ?2 " \
  ""

#define STMT_UPGRADE_TO_31 5
#define STMT_5_INFO {"STMT_UPGRADE_TO_31", NULL}
#define STMT_5 \
  "ALTER TABLE NODES ADD COLUMN inherited_props BLOB; " \
  "DROP INDEX IF EXISTS I_ACTUAL_CHANGELIST; " \
  "DROP INDEX IF EXISTS I_EXTERNALS_PARENT; " \
  "DROP INDEX I_NODES_PARENT; " \
  "CREATE UNIQUE INDEX I_NODES_PARENT ON NODES (wc_id, parent_relpath, " \
  "                                             local_relpath, op_depth); " \
  "DROP INDEX I_ACTUAL_PARENT; " \
  "CREATE UNIQUE INDEX I_ACTUAL_PARENT ON ACTUAL_NODE (wc_id, parent_relpath, " \
  "                                                    local_relpath); " \
  "PRAGMA user_version = 31; " \
  ""

#define STMT_UPGRADE_31_SELECT_WCROOT_NODES 6
#define STMT_6_INFO {"STMT_UPGRADE_31_SELECT_WCROOT_NODES", NULL}
#define STMT_6 \
  "SELECT l.wc_id, l.local_relpath FROM nodes as l " \
  "LEFT OUTER JOIN nodes as r " \
  "ON l.wc_id = r.wc_id " \
  "   AND r.local_relpath = l.parent_relpath " \
  "   AND r.op_depth = 0 " \
  "WHERE l.op_depth = 0 " \
  "  AND l.repos_path != '' " \
  "  AND ((l.repos_id IS NOT r.repos_id) " \
  "       OR (l.repos_path IS NOT (CASE WHEN (r.local_relpath) = '' THEN (CASE WHEN (r.repos_path) = '' THEN (l.local_relpath) WHEN (l.local_relpath) = '' THEN (r.repos_path) ELSE (r.repos_path) || '/' || (l.local_relpath) END) WHEN (r.repos_path) = '' THEN (CASE WHEN (r.local_relpath) = '' THEN (l.local_relpath)  WHEN SUBSTR((l.local_relpath), 1, LENGTH(r.local_relpath)) = (r.local_relpath)  THEN CASE WHEN LENGTH(r.local_relpath) = LENGTH(l.local_relpath) THEN '' WHEN SUBSTR((l.local_relpath), LENGTH(r.local_relpath)+1, 1) = '/' THEN SUBSTR((l.local_relpath), LENGTH(r.local_relpath)+2) END END) WHEN SUBSTR((l.local_relpath), 1, LENGTH(r.local_relpath)) = (r.local_relpath) THEN CASE WHEN LENGTH(r.local_relpath) = LENGTH(l.local_relpath) THEN (r.repos_path) WHEN SUBSTR((l.local_relpath), LENGTH(r.local_relpath)+1, 1) = '/' THEN (r.repos_path) || SUBSTR((l.local_relpath), LENGTH(r.local_relpath)+1) END END))) " \
  ""

#define WC_METADATA_SQL_99 \
  "CREATE TABLE ACTUAL_NODE_BACKUP ( " \
  "  wc_id  INTEGER NOT NULL, " \
  "  local_relpath  TEXT NOT NULL, " \
  "  parent_relpath  TEXT, " \
  "  properties  BLOB, " \
  "  conflict_old  TEXT, " \
  "  conflict_new  TEXT, " \
  "  conflict_working  TEXT, " \
  "  prop_reject  TEXT, " \
  "  changelist  TEXT, " \
  "  text_mod  TEXT " \
  "  ); " \
  "INSERT INTO ACTUAL_NODE_BACKUP SELECT " \
  "  wc_id, local_relpath, parent_relpath, properties, conflict_old, " \
  "  conflict_new, conflict_working, prop_reject, changelist, text_mod " \
  "FROM ACTUAL_NODE; " \
  "DROP TABLE ACTUAL_NODE; " \
  "CREATE TABLE ACTUAL_NODE ( " \
  "  wc_id  INTEGER NOT NULL REFERENCES WCROOT (id), " \
  "  local_relpath  TEXT NOT NULL, " \
  "  parent_relpath  TEXT, " \
  "  properties  BLOB, " \
  "  conflict_old  TEXT, " \
  "  conflict_new  TEXT, " \
  "  conflict_working  TEXT, " \
  "  prop_reject  TEXT, " \
  "  changelist  TEXT, " \
  "  text_mod  TEXT, " \
  "  PRIMARY KEY (wc_id, local_relpath) " \
  "  ); " \
  "CREATE UNIQUE INDEX I_ACTUAL_PARENT ON ACTUAL_NODE (wc_id, parent_relpath, " \
  "                                                    local_relpath); " \
  "INSERT INTO ACTUAL_NODE SELECT " \
  "  wc_id, local_relpath, parent_relpath, properties, conflict_old, " \
  "  conflict_new, conflict_working, prop_reject, changelist, text_mod " \
  "FROM ACTUAL_NODE_BACKUP; " \
  "DROP TABLE ACTUAL_NODE_BACKUP; " \
  ""

#define WC_METADATA_SQL_DECLARE_STATEMENTS(varname) \
  static const char * const varname[] = { \
    STMT_0, \
    STMT_1, \
    STMT_2, \
    STMT_3, \
    STMT_4, \
    STMT_5, \
    STMT_6, \
    NULL \
  }

#define WC_METADATA_SQL_DECLARE_STATEMENT_INFO(varname) \
  static const char * const varname[][2] = { \
    STMT_0_INFO, \
    STMT_1_INFO, \
    STMT_2_INFO, \
    STMT_3_INFO, \
    STMT_4_INFO, \
    STMT_5_INFO, \
    STMT_6_INFO, \
    {NULL, NULL} \
  }
