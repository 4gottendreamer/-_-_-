using System;

namespace test_cs
{
	class TestClass
	{
		public TestClass()
		{
			m_Int = 0;
			m_Str = "\0";
			Console.WriteLine("Object instanciated");
		}

		public void WriteLine()
		{
			Console.WriteLine(m_Str + ' ' + m_Int);
		}
		public void Write()
		{
			Console.Write(m_Str + ' ' + m_Int);
		}
		public int Integer
		{
			get { return m_Int; }
			set { m_Int = value; }
		}
		public string String
		{
			get { return m_Str; }
			set { m_Str = value; }
		}

		private int m_Int = 0;
		private string m_Str = "\0";
	}
}
