
namespace moeTest{

void init_ctx( mol::di::Context& ctx) 
{

	mol::di::ContextBuilder builder(ctx);

	builder.addSingleton<test::Test>(
		mol::di::constructor<test::Test, test::Test>(
			mol::di::arg<Logger*>("theOtherLogger"), 
			mol::di::arg<Drive*>(), 
			mol::di::arg<Printer*>()) 
		);

	builder.addSingleton<Logger>(
		"theLogger"
		)
		->depends(mol::di::dependency(&Logger::greeting, mol::di::value<std::string>("heya")) );

	builder.addSingleton<Logger>(
		"theOtherLogger"
		)
		->depends(mol::di::dependency("greet.de", &Logger::greeting));

	builder.addSingleton<Drive>(
		mol::di::constructor<Drive,Drive>(
			mol::di::arg<Logger>("theLogger")) 
		);

	builder.addValue<int>( "counter", "0");
	builder.addFactory<Printer>()
		->depends(mol::di::dependency("theList", &Printer::list));

	builder.addFactory<App>()
		->depends(mol::di::dependency(&App::test))
		->depends(mol::di::dependency("theMap",&App::map_));

	
	builder.addList<std::string>("theList")
		->add( mol::di::value<std::string>("my \"textitext\" 1") )
		->add( mol::di::value<std::string>("my 'textitext' 2") );

	builder.addValue<std::string>( "key-a", "key-1 (!)");

	builder.addMap<std::string,std::string>("theMap")
		->add( mol::di::arg<std::string>("key-a"), mol::di::value<std::string>("value-a") )
		->add( mol::di::value<std::string>("key-2"), mol::di::value<std::string>("value-b") );

	builder.addValue<std::string>( "greet", "\n    hello\n    world\n  ");
	builder.addValue<std::string>( "greet.de", "hullo");
	//builder.addValue<std::string>( "null", "heya");
	
	builder.resolve();
}

}
