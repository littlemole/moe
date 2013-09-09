var IOC = function () {

    var writeToFile = function (file, sText) {

        var fso = new ActiveXObject("Scripting.FileSystemObject");
        var FileObject = fso.CreateTextFile(file, true); // 8=append, true=create if not exist, 0 = ASCII
        FileObject.write(sText)
        FileObject.close()
    };

    var loadDocument = function (xml) {
        var objXML = new ActiveXObject("MSXML2.DOMDocument");
        objXML.async = false;
        objXML.load(xml);
        return objXML;
    };

    var escpapeString = function (s) {
        s = s.replace(/\t/gi, "\\t");
        s = s.replace(/\r/gi, "\\r");
        s = s.replace(/\n/gi, "\\n");
        s = s.replace(/"/gi, "\\\"");
        return s;
    };

    var describeValue = function (clazz, name, value) {

        var cpp = "";
        cpp += "\tbuilder.addValue<" + clazz + ">( \"" + name + "\", \"" + escpapeString(value) + "\");\r\n";
        return cpp;
    };

    var describeConstructor = function (clazz, name, impl, args) {

        var cpp = "";

        if (name == null && (args == null || args.length == 0)) {
            return clazz + ">()";
        }

        cpp += clazz;
        cpp += ">(\r\n\t";
        if (name != null) {
            cpp += "\t\"";
            cpp += name;
            cpp += "\"";
        }
        if (args != null && args.length > 0) {
            if (name != null) {
                cpp += ", \r\n";
            }
            cpp += "\tmol::di::constructor<" + clazz;
            if (impl != null) {
                cpp += ", ";
                cpp += impl;
            }

            cpp += ">(";
            for (var i = 0; i < args.length; i++) {

                var n = args[i].getAttribute("name");
                var c = args[i].getAttribute("type") || "std::string";

                if (i > 0) {
                    cpp += ", ";
                }
                cpp += "\r\n\t\t\t";
                if (n != null) {

                    cpp += "mol::di::arg<" + c + ">(\"" + n + "\")";
                }
                else {
                    cpp += "mol::di::arg<" + c + ">()";
                }
            }
            cpp += ") ";
        }
        cpp += "\r\n\t\t)";
        return cpp;
    };



    var describeSingletonConstructor = function (clazz, name, object, impl) {

        var args = object.selectNodes("./constructor/arg");
        var cpp = "";


        //        if (name) {
        //          cpp += "builder.addNamedSingleton<";
        //    } else {
        cpp += "\tbuilder.addSingleton<";
        //  }

        cpp += describeConstructor(clazz, name, impl, args);
        return cpp;

    };

    var describeFactoryConstructor = function (clazz, name, object, impl) {

        var args = object.selectNodes("./constructor/arg");
        var cpp = "";

        //  if (name) {
        //      cpp += "builder.addNamedFactory<";
        //  } else {
        cpp += "\tbuilder.addFactory<"
        //  }

        cpp += describeConstructor(clazz, name, impl, args);
        return cpp;
    };

    var describeDependencies = function (clazz, object) {

        var cpp = "\r\n";
        var dependencies = object.selectNodes("./dependencies/dependency");
        if (dependencies == null || dependencies.length == 0) {
            return ";\r\n";
        }
        for (var j = 0; j < dependencies.length; j++) {

            var member = dependencies[j].getAttribute("member");
            var name = dependencies[j].getAttribute("name");
            var member = dependencies[j].getAttribute("member");
            var values = dependencies[j].selectSingleNode("value");

            if (values != null) {

                var type = values.getAttribute("type") || "std::string";
                var value = values.firstChild.nodeValue;

                cpp += "\t\t->add(mol::di::dependency(&" + clazz + "::" + member + ", mol::di::value<" + type +">(\"" + escpapeString(value) + "\")) );\r\n";
            }
            else if (name == null) {
                cpp += "\t\t->add(mol::di::dependency(&" + clazz + "::" + member + "));\r\n";
            }
            else {
                cpp += "\t\t->add(mol::di::dependency(\"" + name + "\", &" + clazz + "::" + member + "));\r\n";
            }
        }
        return cpp;
    };

    var describeSingleton = function (object) {

        var cpp = "";

        var clazz = object.getAttribute("type");
        var name = object.getAttribute("name");
        var value = object.getAttribute("value");
        var impl = object.getAttribute("impl");

        if (value != null && name != null) {

            return describeValue(clazz, name, value);
        }

        cpp += describeSingletonConstructor(clazz, name, object, impl);
        cpp += describeDependencies(clazz, object);
        cpp += "\r\n";
        return cpp;
    };


    var describeFactory = function (object) {

        var cpp = "";

        var clazz = object.getAttribute("type");
        var name = object.getAttribute("name");
        var value = object.getAttribute("value");
        var impl = object.getAttribute("impl");

        if (value != null && name != null) {

            return describeValue(clazz, name, value);
        }

        cpp += describeFactoryConstructor(clazz, name, object, impl);
        cpp += describeDependencies(clazz, object);
        cpp += "\r\n";
        return cpp;
    };

    var describeList = function (object, container) {

        var cpp = "";

        var clazz = object.getAttribute("type") || "std::string";
        var name = object.getAttribute("name");


        cpp += "\tbuilder.add" + container + "<" + clazz + ">(\"" + name + "\")";

        var items = object.selectNodes("./item");
        for (var i = 0; i < items.length; i++) {

            var n = items[i].getAttribute("name");
            var value = items[i].firstChild.nodeValue;

            if (n != null) {
                cpp += "\r\n\t\t->add( mol::di::arg<" + clazz + ">(\"" + n + "\") )";
            } else {
                cpp += "\r\n\t\t->add( mol::di::value<" + clazz + ">(\"" + escpapeString(value) + "\") )";
            }
        }

        cpp += ";\r\n";
        return cpp;
    };


    var describeMap = function (object) {

        var cpp = "";

        var key = object.getAttribute("key") || "std::string";
        var value = object.getAttribute("value") || "std::string";
        var name = object.getAttribute("name");

        cpp += "\tbuilder.addMap<" + key + ", " + value + ">(\"" + name + "\")";

        var items = object.selectNodes("./item");
        for (var i = 0; i < items.length; i++) {

            var k = items[i].getAttribute("key");
            var n = items[i].getAttribute("name");
            var v = items[i].firstChild.nodeValue;

            if (n != null) {
                cpp += "\r\n\t\t->add( mol::di::value<" + key + ">(\"" + escpapeString(k) + "\") ), mol::di::arg<" + value + ">(\"" + n + "\"))";
            } else {
                cpp += "\r\n\t\t->add( mol::di::value<" + key + ">(\"" + escpapeString(k) + "\"), mol::di::value<" + value + ">(\"" + escpapeString(v) + "\"))";
            }
        }

        cpp += ";\r\n";
        return cpp;
    };

    var describeSingletons = function (xml) {

        var cpp = "";

        var objects = xml.selectNodes("//singleton");
        for (var i = 0; i < objects.length; i++) {

            cpp += describeSingleton(objects[i]);
        }

        return cpp;
    };

    var describeFactories = function (xml) {

        var cpp = "";
        var objects = xml.selectNodes("//factory");
        for (var i = 0; i < objects.length; i++) {

            cpp += describeFactory(objects[i]);
        }

        return cpp;
    };


    var describeLists = function (xml) {

        var cpp = "";
        var objects = xml.selectNodes("//list");
        for (var i = 0; i < objects.length; i++) {

            cpp += describeList(objects[i] , "List" );
        }

        return cpp;
    };


    var describeVectors = function (xml) {

        var cpp = "";
        var objects = xml.selectNodes("//vector");
        for (var i = 0; i < objects.length; i++) {

            cpp += describeList(objects[i], "Vector");
        }

        return cpp;
    };

    var describeMaps = function (xml) {

        var cpp = "";
        var objects = xml.selectNodes("//map");
        for (var i = 0; i < objects.length; i++) {

            cpp += describeMap(objects[i]);
        }

        return cpp;
    };


    var describeValues = function (xml) {

        var cpp = "";

        var objects = xml.selectNodes("//value");
        for (var i = 0; i < objects.length; i++) {

            var clazz = objects[i].getAttribute("type") || "std::string";
            var name = objects[i].getAttribute("name");
            var value = objects[i].firstChild.nodeValue;

            cpp += describeValue(clazz, name, value);
        }

        return cpp;
    };



    var ioc = {

        writeContextImpl: function (xmlFile, cppFile) {

            var objShell = WScript.CreateObject("WScript.Shell");
            var xml = loadDocument(objShell.CurrentDirectory + "\\" + xmlFile);

            var ns = xml.selectSingleNode("//context").getAttribute("namespace");
            var cpp = "\r\nnamespace " + ns + "{\r\n\r\n";
            cpp += "void init_ctx() \r\n{\r\n\r\n\tmol::di::ContextBuilder builder;\r\n\r\n";

            cpp += describeSingletons(xml);
            cpp += describeFactories(xml);
            cpp += describeVectors(xml);
            cpp += describeLists(xml);
            cpp += describeMaps(xml);
            cpp += describeValues(xml);

            cpp += "\r\n\tbuilder.resolve();\r\n}\r\n\r\n\}\r\n";
            writeToFile(objShell.CurrentDirectory + "\\" + cppFile, cpp);
        }
    };
    return ioc;
};

var ioc = IOC();
ioc.writeContextImpl("ioc.xml", "ioc.cpp" );

