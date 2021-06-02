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

		//
		// Lab05
		//

		private void buttonLab05FillArray_Click(object sender, EventArgs e)
		{
			int rowsCount = Convert.ToInt32(numericUpDownLab05RowsAuto.Value);
			double[] array = LabMethods.GetDoubleArray(rowsCount, 20);
			dataGridViewLab05.RowCount = array.Length;
			for (int i = 0; i < array.Length; i++) {
				dataGridViewLab05.Rows[i].Cells[0].Value = (i + 1).ToString();
				dataGridViewLab05.Rows[i].Cells[1].Value = array[i].ToString();
				dataGridViewLab05.Rows[i].Cells[2].Value = LabMethods.Factorial(i).ToString();
			}
			textBoxLab05Result.Clear();
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = new bool[0];
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

			dataGridViewLab05.AllowUserToAddRows = true;
			dataGridViewLab05.AllowUserToDeleteRows = true;
			dataGridViewLab05.ReadOnly = false;
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
			checkBoxLab05RowsHighlight_CheckedChanged(sender, e);
		}

		private void numericUpDownLab05RowsManual_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab05.RowCount = Convert.ToInt32(numericUpDownLab05RowsManual.Value);
			numericUpDownLab05RowsAuto.Value = numericUpDownLab05RowsManual.Value;
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = new bool[0];
		}

		private void numericUpDownLab05RowsAuto_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab05.RowCount = Convert.ToInt32(numericUpDownLab05RowsAuto.Value);
			numericUpDownLab05RowsManual.Value = numericUpDownLab05RowsAuto.Value;
			dataGridViewLab05.ClearSelection();
			LabMethods.Lab05CheckedIndices = new bool[0];
		}

		private void dataGridViewLab05_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
		{
			if (dataGridViewLab05.RowCount > 0) {
				// TODO: reindexate
			}
			numericUpDownLab05RowsAuto.Value = dataGridViewLab05.RowCount;
		}

		private void dataGridViewLab05_UserAddedRow(object sender, DataGridViewRowEventArgs e)
		{
			dataGridViewLab05_Reindexate();
			numericUpDownLab05RowsAuto.Value = dataGridViewLab05.RowCount;
		}

		private void dataGridViewLab05_Reindexate()
		{
			for (int i = 0; i < dataGridViewLab05.RowCount; i++) {
				dataGridViewLab05.Rows[i].Cells[0].Value = (i + 1).ToString();
				dataGridViewLab05.Rows[i].Cells[2].Value = LabMethods.Factorial(i + 1);
			}
		}

		private void checkBoxLab05RowsHighlight_CheckedChanged(object sender, EventArgs e)
		{
			if (checkBoxLab05RowsHighlight.Checked) {
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

		private void groupBoxLab06_Enter(object sender, EventArgs e)
		{

		}

		private void buttonLab06FillArray_Click(object sender, EventArgs e)
		{
			int rowsCount = Convert.ToInt32(numericUpDownLab06RowsAuto.Value);
			int[] array = LabMethods.GetIntArray(rowsCount, 0, 100000);
			dataGridViewLab06.RowCount = array.Length;
			for (int i = 0; i < array.Length; i++) {
				dataGridViewLab06.Rows[i].Cells[0].Value = (i + 1).ToString();
				dataGridViewLab06.Rows[i].Cells[1].Value = array[i].ToString();
				dataGridViewLab06.Rows[i].Cells[2].Value = LabMethods.DigitsCount(array[i]).ToString();
			}
			dataGridViewLab06.ClearSelection();
		}

		private void numericUpDownLab06RowsAuto_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab06.RowCount = Convert.ToInt32(numericUpDownLab06RowsAuto.Value);
			numericUpDownLab06RowsManual.Value = numericUpDownLab06RowsAuto.Value;
			dataGridViewLab06.ClearSelection();
		}

		private void buttonLab06Execute_Click(object sender, EventArgs e)
		{
			dataGridViewLab06_Reindexate();
			long[] array = new long[dataGridViewLab06.RowCount];
			for (int i = 0; i < array.Length; i++) {
				array[i] = Convert.ToInt64(dataGridViewLab06.Rows[i].Cells[1].Value);
			}
			int index = LabMethods.Lab06(array);

			dataGridViewLab06.ClearSelection();
			dataGridViewLab06.Rows[index].Selected = true;
		}

		private void radioButtonLab06AutoFill_CheckedChanged(object sender, EventArgs e)
		{
			labelLab06RowsAuto.Enabled = true;
			buttonLab06FillArray.Enabled = true;
			numericUpDownLab06RowsAuto.Enabled = true;

			numericUpDownLab06RowsManual.Enabled = false;
			labelLab06RowsManual.Enabled = false;

			dataGridViewLab05.ClearSelection();
		}

		private void radioButtonLab06ManualFill_CheckedChanged(object sender, EventArgs e)
		{
			labelLab06RowsAuto.Enabled = false;
			buttonLab06FillArray.Enabled = false;
			numericUpDownLab06RowsAuto.Enabled = false;

			numericUpDownLab06RowsManual.Enabled = true;
			labelLab06RowsManual.Enabled = true;

			dataGridViewLab06.ClearSelection();

			dataGridViewLab06.AllowUserToAddRows = true;
			dataGridViewLab06.AllowUserToDeleteRows = true;
			dataGridViewLab06.ReadOnly = false;
		}

		private void numericUpDownLab06RowsManual_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab06.RowCount = Convert.ToInt32(numericUpDownLab06RowsManual.Value);
			numericUpDownLab06RowsAuto.Value = numericUpDownLab06RowsManual.Value;
			dataGridViewLab06.ClearSelection();
		}

		private void dataGridViewLab06_UserAddedRow(object sender, DataGridViewRowEventArgs e)
		{
			dataGridViewLab06_Reindexate();
			numericUpDownLab06RowsAuto.Value = dataGridViewLab06.RowCount;
			numericUpDownLab06RowsManual.Value = dataGridViewLab06.RowCount;

		}

		private void dataGridViewLab06_Reindexate()
		{
			for (int i = 0; i < dataGridViewLab06.RowCount; i++) {
				dataGridViewLab06.Rows[i].Cells[0].Value = (i + 1).ToString();
				dataGridViewLab06.Rows[i].Cells[2].Value =
					LabMethods.DigitsCount(
						Convert.ToInt32(dataGridViewLab06.Rows[i].Cells[1].Value)
						).ToString();
			}
		}

		private void numericUpDownLab07AutoRows_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab07.RowCount = Convert.ToInt32(numericUpDownLab07AutoRows.Value);
			numericUpDownLab07ManualRows.Value = numericUpDownLab07AutoRows.Value;
			dataGridViewLab07.ClearSelection();

		}

		private void numericUpDownLab07AutoColumns_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab07.ColumnCount = Convert.ToInt32(numericUpDownLab07AutoColumns.Value);
			numericUpDownLab07ManualColumns.Value = numericUpDownLab07AutoColumns.Value;
			dataGridViewLab07.ClearSelection();
		}

		private void buttonLab07AutoFill_Click(object sender, EventArgs e)
		{
			int rowsCount = Convert.ToInt32(numericUpDownLab07AutoRows.Value);
			int columnsCount = Convert.ToInt32(numericUpDownLab07AutoColumns.Value);
			int[,] array2d = LabMethods.GetIntArray2(rowsCount, columnsCount, -10, 10);
			for (int i = 0; i < rowsCount; i++) {
				for (int j = 0; j < columnsCount; j++) {
					dataGridViewLab07.Rows[i].Cells[j].Value = array2d[i, j].ToString();
				}
			}
			dataGridViewLab07.AutoResizeColumns();
			dataGridViewLab07.ClearSelection();
		}

		private void radioButtonLab07Auto_CheckedChanged(object sender, EventArgs e)
		{
			numericUpDownLab07ManualColumns.Enabled = false;
			numericUpDownLab07ManualRows.Enabled = false;
			labelLab07ManualColumnsCount.Enabled = false;
			labelLab07ManualRowsCount.Enabled = false;

			numericUpDownLab07AutoColumns.Enabled = true;
			numericUpDownLab07AutoRows.Enabled = true;
			labelLab07AutoRowsCount.Enabled = true;
			labelLab07AutoColumnsCount.Enabled = true;

			buttonLab07AutoFill.Enabled = true;
			dataGridViewLab07.ReadOnly = true;
		}

		private void radioButtonLab07Manual_CheckedChanged(object sender, EventArgs e)
		{
			numericUpDownLab07ManualColumns.Enabled = true;
			numericUpDownLab07ManualRows.Enabled = true;
			labelLab07ManualColumnsCount.Enabled = true;
			labelLab07ManualRowsCount.Enabled = true;

			numericUpDownLab07AutoColumns.Enabled = false;
			numericUpDownLab07AutoRows.Enabled = false;
			labelLab07AutoRowsCount.Enabled = false;
			labelLab07AutoColumnsCount.Enabled = false;

			buttonLab07AutoFill.Enabled = false;
			dataGridViewLab07.ReadOnly = false;
		}

		private void numericUpDownLab07ManualRows_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab07.RowCount = Convert.ToInt32(numericUpDownLab07ManualRows.Value);
			numericUpDownLab07AutoRows.Value = numericUpDownLab07ManualRows.Value;
			dataGridViewLab07.ClearSelection();
		}

		private void numericUpDownLab07ManualColumns_ValueChanged(object sender, EventArgs e)
		{
			dataGridViewLab07.ColumnCount = Convert.ToInt32(numericUpDownLab07ManualColumns.Value);
			numericUpDownLab07AutoColumns.Value = numericUpDownLab07ManualColumns.Value;
			dataGridViewLab07.ClearSelection();
		}

		private void buttonLab07Execute_Click(object sender, EventArgs e)
		{
			dataGridViewLab07.ClearSelection();
			int rowsCount = dataGridViewLab07.RowCount;
			int columnsCount = dataGridViewLab07.ColumnCount;
			int[,] array2d = new int[rowsCount, columnsCount];
			for (int i = 0; i < rowsCount; i++) {
				for (int j = 0; j < columnsCount; j++) {
					array2d[i, j] = Convert.ToInt32(dataGridViewLab07.Rows[i].Cells[j].Value);
				}
			}
			int rowIndex = LabMethods.Lab07(array2d);
			if (rowIndex > -1) {
				labelLab07Answer.Text = $"Номер столбца с максимальным\nколичеством нулей: {rowIndex}";
				for (int i = 0; i < rowsCount; i++) {
						dataGridViewLab07.Rows[i].Cells[rowIndex].Value =
						array2d[i, rowIndex].ToString();
				}
				for (int i = 0; i < dataGridViewLab07.RowCount; i++) {
					dataGridViewLab07.Rows[i].Cells[rowIndex].Selected = true;
				}
			}
			else {
				labelLab07Answer.Text = $"Нули в матрице отстутсвуют";
			}
		}
	}
}
