// Вариант 6
/*
	1.	Реализовать графический интерфейс для лабораторной №15
		с помощью создания приложения Windows Forms в среде Visual Studio
	2.	В графическом интерфейсе продемонстрировать использование следующих элементов управления:
+			a. Button
+			b. RadioButton или CheckBox
+			c. TextBox
+			d. Label
+			e. ComboBox
+			f. TabControl
+			g. DataGridView
			h. ListBox
*/

using System;
using System.Windows.Forms;

namespace lab_16_v6
{
	static class lab_16_v6
	{
		/// <summary>
		///  The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.SetHighDpiMode(HighDpiMode.SystemAware);
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new Form1());
		}
	}
}
