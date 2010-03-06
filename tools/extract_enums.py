enum_buff = open('tools/enum.c').read()

#print enum_buff;

print "static void init_enums(PyObject *m){"
for struct_buff in enum_buff.split(';'):
    if not struct_buff.strip(): continue
    #struct_buff = enum_buff[enum_buff.find('typedef enum'): enum_buff.find(';')]
    filtered_buff = []
    for line in struct_buff.split('\n'):
        if 'typedef' in line: continue
        if '{' in line: continue
        if '}' in line:
            enum_name = line.replace('}','').replace(';','').strip()
        elif '*' in line:
            pass
        else:
            filtered_buff.append( line.strip() )

    print "{"
    print "\tPyObject *values;"
    total = 0
    enum = []
    for l in filtered_buff:
        l = l.strip()
        if l:
            try:
                name, doc = l.split(',',1)
            except ValueError:
                if '///' in l:
                    name, doc = l.split('///',1)
                else:
                    name = l.replace(',','')

            try:
                name, _ = name.split('=')
            except:
                pass
            print "\tPyModule_AddIntConstant(m,\"%s\", %s);" % (name.strip(), name.strip())
            total += 1
            enum.append(name.strip())
    print '\tvalues =Py_BuildValue("%s",'%('s'*len(enum)), ',\n\t\t\t\t\t'.join( '\"%s\"' % e for e in enum), ');'
    print "\tPy_INCREF(values);"
    print '\tPyModule_AddObject(m,"%s", values);'% enum_name
    print "}"

print "}"
