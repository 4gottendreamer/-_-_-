using System;
using System.Windows.Forms;


namespace lab_16_v6
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, System.EventArgs e)
		{
			Close();
		}

		private void buttonLab10Execute_Click(object sender, System.EventArgs e)
		{
			richTextBoxLab10Out.Clear();
			string[] lines = textBoxLab10In.Text.Split("\r\n");
			lines = LabMethods.Lab10(lines);
			foreach (var line in lines) {
				richTextBoxLab10Out.AppendText(line + '\n');
			}
		}

		private void buttonLab03Execute_Click(object sender, System.EventArgs e)
		{
			double.TryParse(textBoxLab03x.Text, out double x);
			double.TryParse(textBoxLab03z.Text, out double z);
			textBoxLab03Answer.Text = LabMethods.Lab03(x, z).ToString();
		}

		private void textBoxLab03x_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Enter) {
				textBoxLab03z.Focus();
			}
			if (e.KeyCode == Keys.Escape) {
				textBoxLab03x.Clear();
			}
		}

		private void textBoxLab03z_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Enter) {
				textBoxLab03t.Focus();
			}
			if (e.KeyCode == Keys.Escape) {
				textBoxLab03z.Clear();
			}
		}

		private void textBoxLab03t_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Enter) {
				buttonLab03Execute_Click(sender, e);
			}
			if (e.KeyCode == Keys.Escape) {
				textBoxLab03t.Clear();
			}
		}

		// //////////////
		// Lab05 methods
		// //////////////

		private void buttonLab05FillArray_Click(object sender, EventArgs e)
		{
			int rowsCount = Convert.ToInt32(numericUpDownLab05RowsAuto.Value);
			double[] array = LabMethods.GetDoubleArray(rowsCount, 20);
			dataGridViewLab05.RowCount = array.Length;
			for (int i = 0; i < array.Length; i++) {
				dataGridViewLab05.Rows[i].Cells[0].Value = (i + 1).ToString();
				dataGridViewLab05.Rows[i].Cells[1].Value = array[i].ToString();
				dataGridViewLab05.Rows[i].Cells[2].Value = LabMethods.factorial(i).ToString();
			}
			textBoxLab05Result.Clear();
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = null;
		}

		private void radioButtonLab05AutoFill_CheckedChanged(object sender, EventArgs e)
		{
			labelLab05RowsAuto.Enabled = true;
			buttonLab05FillArray.Enabled = true;
			numericUpDownLab05RowsAuto.Enabled = true;

			numericUpDownLab05RowsManual.Enabled = false;
			labelLab05RowsManual.Enabled = false;

			dataGridViewLab05.ClearSelection();
		}

		private void radioButtonLab05ManualFill_CheckedChanged(object sender, EventArgs e)
		{
			labelLab05RowsAuto.Enabled = false;
			buttonLab05FillArray.Enabled = false;
			numericUpDownLab05RowsAuto.Enabled = false;

			numericUpDownLab05RowsManual.Enabled = true;
			labelLab05RowsManual.Enabled = true;

			dataGridViewLab05.ClearSelection();
		}

		private void buttonLab05Execute_Click(object sender, EventArgs e)
		{
			double[] array = new double[dataGridViewLab05.RowCount];
			for (int i = 0; i < array.Length; i++) {
				array[i] = Convert.ToDouble(dataGridViewLab05.Rows[i].Cells[1].Value);
			}
			double inverseProduct = 1;
			if (LabMethods.Lab05(array, out inverseProduct)) {
				textBoxLab05Result.Text = inverseProduct.ToString();
			}
			else {
				textBoxLab05Result.Text = "Нет удовлетворяющих условию элементов";
			}
			dataGridViewLab05.ClearSelection();
		}

		private void numericUpDownLab05RowsManual_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab05.RowCount = Convert.ToInt32(numericUpDownLab05RowsManual.Value);
			numericUpDownLab05RowsAuto.Value = numericUpDownLab05RowsManual.Value;
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = null;
		}

		private void numericUpDownLab05RowsAuto_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab05.RowCount = Convert.ToInt32(numericUpDownLab05RowsAuto.Value);
			numericUpDownLab05RowsManual.Value = numericUpDownLab05RowsAuto.Value;
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = null;
		}

		private void checkBoxLab05HighlightRows_CheckedChanged(object sender, EventArgs e)
		{
			if (checkBoxLab05HighlightRows.Checked) {
				if (LabMethods.Lab05CheckedIndices.Length > 0) {
					for (int i = 0; i < LabMethods.Lab05CheckedIndices.Length; i++) {
						dataGridViewLab05.Rows[i].Selected =
							LabMethods.Lab05CheckedIndices[i];
					}
				}
			}
			else {
				dataGridViewLab05.ClearSelection();
			}
		}
	}
}
