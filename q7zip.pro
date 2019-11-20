TEMPLATE = subdirs
SUBDIRS += 7zip q7z tests
q7z.depends = 7zip
tests.depends = q7z
