SUBDIRS = syntax po

enc_src =	src/wxm/encoding/cp20932.cpp \
	src/wxm/encoding/cp20932.h \
	src/wxm/encoding/doublebyte.cpp \
	src/wxm/encoding/doublebyte.h \
	src/wxm/encoding/encoding.cpp \
	src/wxm/encoding/encoding.h \
	src/wxm/encoding/encoding_def.h \
	src/wxm/encoding/multibyte.cpp \
	src/wxm/encoding/multibyte.h \
	src/wxm/encoding/gb18030.cpp \
	src/wxm/encoding/gb18030.h \
	src/wxm/encoding/singlebyte.cpp \
	src/wxm/encoding/singlebyte.h \
	src/wxm/encoding/unicode.cpp \
	src/wxm/encoding/unicode.h

encdet_src =	src/wxm/encdet.cpp \
	src/wxm/encdet.h \
	src/wxmedit/mad_encdet.cpp \
	src/wxmedit/mad_encdet.h

bin_PROGRAMS = wxmedit
check_PROGRAMS = wxmedit_test
TESTS = wxmedit_test
wxmedit_LDADD = ${curl_LIBS}
wxmedit_CXXFLAGS = -DDATA_DIR=\"${datadir}\" ${curl_CFLAGS}
wxmedit_SOURCES =	$(enc_src) \
	$(encdet_src) \
	src/dialog/wxm_conv_enc_dialog.cpp \
	src/dialog/wxm_conv_enc_dialog.h \
	src/dialog/wxm_find_in_files_dialog.cpp \
	src/dialog/wxm_find_in_files_dialog.h \
	src/dialog/wxm_highlighting_dialog.cpp \
	src/dialog/wxm_highlighting_dialog.h \
	src/dialog/wxm_purge_histories_dialog.cpp \
	src/dialog/wxm_purge_histories_dialog.h \
	src/dialog/wxm_search_replace_dialog.cpp \
	src/dialog/wxm_search_replace_dialog.h \
	src/dialog/wxm_sort_dialog.cpp \
	src/dialog/wxm_sort_dialog.h \
	src/dialog/wxm_word_count_dialog.cpp \
	src/dialog/wxm_word_count_dialog.h \
	src/dialog/wxmedit_about_dialog.cpp \
	src/dialog/wxmedit_about_dialog.h \
	src/dialog/wxmedit_options_dialog.cpp \
	src/dialog/wxmedit_options_dialog.h \
	src/mad_utils.cpp \
	src/mad_utils.h \
	src/wxm/case_conv.cpp \
	src/wxm/case_conv.h \
	src/wxm/choice_map.hpp \
	src/wxm/def.h \
	src/wxm/edit/inframe.cpp \
	src/wxm/edit/inframe.h \
	src/wxm/edit/simple.cpp \
	src/wxm/edit/simple.h \
	src/wxm/edit/single_line.cpp \
	src/wxm/edit/single_line.h \
	src/wxm/line_enc_adapter.cpp \
	src/wxm/line_enc_adapter.h \
	src/wxm/recent_list.cpp \
	src/wxm/recent_list.h \
	src/wxm/searcher.cpp \
	src/wxm/searcher.h \
	src/wxm/status_bar.cpp \
	src/wxm/status_bar.h \
	src/wxm/update.cpp \
	src/wxm/update.h \
	src/wxm/utils.cpp \
	src/wxm/utils.h \
	src/wxm/wx_avoid_wxmsw_bug4373.h \
	src/wxm/wx_icu.cpp \
	src/wxm/wx_icu.h \
	src/wxm_command.h \
	src/wxm_plugin.cpp \
	src/wxm_plugin.h \
	src/wxm_printout.cpp \
	src/wxm_printout.h \
	src/wxmedit/caret_new.cpp \
	src/wxmedit/caret_new.h \
	src/wxmedit/clipbrd_gtk.cpp \
	src/wxmedit/clipbrd_gtk.h \
	src/wxmedit/trad_simp.cpp \
	src/wxmedit/trad_simp.h \
	src/wxmedit/ucs4_t.h \
	src/wxmedit/wxm_deque.hpp \
	src/wxmedit/wxm_lines.cpp \
	src/wxmedit/wxm_lines.h \
	src/wxmedit/wxm_syntax.cpp \
	src/wxmedit/wxm_syntax.h \
	src/wxmedit/wxm_undo.cpp \
	src/wxmedit/wxm_undo.h \
	src/wxmedit/wxmedit.cpp \
	src/wxmedit/wxmedit.h \
	src/wxmedit/wxmedit_advanced.cpp \
	src/wxmedit/wxmedit_basic.cpp \
	src/wxmedit/wxmedit_command.cpp \
	src/wxmedit/wxmedit_command.h \
	src/wxmedit/wxmedit_gtk.cpp \
	src/wxmedit_app.cpp \
	src/wxmedit_app.h \
	src/wxmedit_frame.cpp \
	src/wxmedit_frame.h \
	src/xm/cxx11.h \
	src/xm/remote.cpp \
	src/xm/remote.h \
	src/xm/ublock.cpp \
	src/xm/ublock.h \
	src/xm/ublock_des.cpp \
	src/xm/utils.hpp \
	src/xm/uutils.cpp \
	src/xm/uutils.h

wxmedit_test_SOURCES =	$(enc_src) \
	$(encdet_src) \
	src/wxm/line_enc_adapter.h \
	src/wxmedit/ucs4_t.h \
	src/wxmedit/wxm_deque.hpp \
	src/xm/cxx11.h \
	src/xm/utils.hpp \
	test/encdet/data_from_icudet.cpp \
	test/encdet/data_from_icudet.h \
	test/encdet/data_from_mozdet.cpp \
	test/encdet/data_from_mozdet.h \
	test/encdet/test_detenc.cpp \
	test/encdet/test_detenc.h \
	test/encdet/test_from_icudet.cpp \
	test/encdet/test_from_mozdet.cpp \
	test/encdet/test_wxmedit_encdet.cpp \
	test/encoding/data_cp20932_conv.cpp \
	test/encoding/data_cp932_conv.cpp \
	test/encoding/data_cp936_conv.cpp \
	test/encoding/data_cp949_conv.cpp \
	test/encoding/data_cp950_conv.cpp \
	test/encoding/data_gb18030_bmp2db.cpp \
	test/encoding/data_gb18030_bmp2qb.cpp \
	test/encoding/data_gb18030_db2bmp.cpp \
	test/encoding/data_gb18030_qb2bmp.cpp \
	test/encoding/data_multibyte_conv.h \
	test/encoding/data_singlebyte_conv.cpp \
	test/encoding/data_singlebyte_conv.h \
	test/encoding/test_doublebyte_conv.cpp \
	test/encoding/test_gb18030_conv.cpp \
	test/encoding/test_singlebyte_conv.cpp \
	test/encdet_test.h \
	test/encoding_test.h \
	test/test.cpp

wxmedit_test_LDFLAGS = @TESTLIBS@

dist_doc_DATA = ChangeLog LICENSE README.txt

pixmapsdir = $(datadir)/pixmaps
pixmaps_DATA = wxmedit.png

wxmedit.desktop: $(top_srcdir)/wxmedit.desktop._ Makefile
	sed "s#@pixmapsdir@#$(pixmapsdir)#" $(top_srcdir)/wxmedit.desktop._ > $@

CLEANFILES = wxmedit.desktop

appdir = $(datadir)/applications
app_DATA = wxmedit.desktop

EXTRA_DIST = $(pixmaps_DATA) $(app_DATA)

noinst_HEADERS =	README.txt \
	autogen.sh \
	src/wxmedit_app.rc \
	src/dialog/wxm_file_association_dialog.cpp \
	src/dialog/wxm_file_association_dialog.h \
	src/plugin_example/makefile.linux \
	src/plugin_example/makefile.mingw32 \
	src/plugin_example/makefile.vc \
	src/plugin_example/plugin.cpp \
	src/plugin_example/vc_cl.bat \
	src/plugin_example/wxwin16x16.xpm \
	images/closeall.xpm \
	images/columnmode.xpm \
	images/comment.xpm \
	images/copy.xpm \
	images/cut.xpm \
	images/down.xpm \
	images/fileclose.xpm \
	images/fileopen.xpm \
	images/filesave.xpm \
	images/filesaveas.xpm \
	images/find.xpm \
	images/findnext.xpm \
	images/findprev.xpm \
	images/font.xpm \
	images/fontname.xpm \
	images/fontsize.xpm \
	images/hexmode.xpm \
	images/indent.xpm \
	images/madedit.ico \
	images/madedit.xpm \
	images/new.xpm \
	images/nowrap.xpm \
	images/null.xpm \
	images/paste.xpm \
	images/preview.xpm \
	images/print.xpm \
	images/quit.xpm \
	images/redo.xpm \
	images/replace.xpm \
	images/saveall.xpm \
	images/textmode.xpm \
	images/uncomment.xpm \
	images/undo.xpm \
	images/unindent.xpm \
	images/wrapbycol.xpm \
	images/wrapbywin.xpm \
	images/wxmedit.ico \
	images/wxmedit.xpm \
	images/wxmedit_16x15.xpm \
	po/wxmedit.pot \
	po/src.list \
	po/wxstd.po.cpp \
	po/xgettext.bat \
	po/xgettext_join.bat


DOMAIN = wxmedit
podir = $(top_srcdir)/po
LINGUAS = @ALL_LINGUAS@
