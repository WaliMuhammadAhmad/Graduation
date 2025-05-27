namespace Lab2_Task_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" && textBox2.Text != "")
            {
                if (Class1.count!=0)
                {
                    for (int i = 0; i < Class1.count; i++)
                    {
                        if (textBox1.Text == (string)Class1.userName[i] && textBox2.Text == (string)Class1.Password[i])
                        {
                            MessageBox.Show("Validate User");
                            this.Close();
                            Form4 form4 = new Form4();
                            form4.ShowDialog();
                            break;
                        }
                        else
                        {
                            MessageBox.Show("Invalidate User");
                        }
                    }
                }
                else
                {
                    MessageBox.Show("Invalidate User");
                }
            }
            else
            {
                MessageBox.Show("Please fill the required fields");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 F2 = new Form2();
            F2.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form3 F3 = new Form3();
            F3.Show();
        }
    }
}