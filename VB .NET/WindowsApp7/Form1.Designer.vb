<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.RadioButtonSenaiKuc = New System.Windows.Forms.RadioButton()
        Me.RadioButtonSenaiKul = New System.Windows.Forms.RadioButton()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.RadioButtonTwoWay = New System.Windows.Forms.RadioButton()
        Me.RadioButtonOneWay = New System.Windows.Forms.RadioButton()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.TextBoxNOPassenger = New System.Windows.Forms.TextBox()
        Me.LabelTotal = New System.Windows.Forms.Label()
        Me.ButtonCalculate = New System.Windows.Forms.Button()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.RadioButtonSenaiKuc)
        Me.GroupBox1.Controls.Add(Me.RadioButtonSenaiKul)
        Me.GroupBox1.Location = New System.Drawing.Point(56, 39)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(200, 100)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "GroupBox1"
        '
        'RadioButtonSenaiKuc
        '
        Me.RadioButtonSenaiKuc.AutoSize = True
        Me.RadioButtonSenaiKuc.Location = New System.Drawing.Point(27, 57)
        Me.RadioButtonSenaiKuc.Name = "RadioButtonSenaiKuc"
        Me.RadioButtonSenaiKuc.Size = New System.Drawing.Size(114, 20)
        Me.RadioButtonSenaiKuc.TabIndex = 1
        Me.RadioButtonSenaiKuc.TabStop = True
        Me.RadioButtonSenaiKuc.Text = "Senai-Kuching" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        Me.RadioButtonSenaiKuc.UseVisualStyleBackColor = True
        '
        'RadioButtonSenaiKul
        '
        Me.RadioButtonSenaiKul.AutoSize = True
        Me.RadioButtonSenaiKul.Location = New System.Drawing.Point(27, 31)
        Me.RadioButtonSenaiKul.Name = "RadioButtonSenaiKul"
        Me.RadioButtonSenaiKul.Size = New System.Drawing.Size(145, 20)
        Me.RadioButtonSenaiKul.TabIndex = 0
        Me.RadioButtonSenaiKul.TabStop = True
        Me.RadioButtonSenaiKul.Text = "Senai-KualaLumpur"
        Me.RadioButtonSenaiKul.UseVisualStyleBackColor = True
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.RadioButtonTwoWay)
        Me.GroupBox2.Controls.Add(Me.RadioButtonOneWay)
        Me.GroupBox2.Location = New System.Drawing.Point(56, 224)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(200, 100)
        Me.GroupBox2.TabIndex = 2
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "GroupBox2"
        '
        'RadioButtonTwoWay
        '
        Me.RadioButtonTwoWay.AutoSize = True
        Me.RadioButtonTwoWay.Location = New System.Drawing.Point(27, 57)
        Me.RadioButtonTwoWay.Name = "RadioButtonTwoWay"
        Me.RadioButtonTwoWay.Size = New System.Drawing.Size(85, 20)
        Me.RadioButtonTwoWay.TabIndex = 1
        Me.RadioButtonTwoWay.TabStop = True
        Me.RadioButtonTwoWay.Text = "Two Way"
        Me.RadioButtonTwoWay.UseVisualStyleBackColor = True
        '
        'RadioButtonOneWay
        '
        Me.RadioButtonOneWay.AutoSize = True
        Me.RadioButtonOneWay.Location = New System.Drawing.Point(27, 31)
        Me.RadioButtonOneWay.Name = "RadioButtonOneWay"
        Me.RadioButtonOneWay.Size = New System.Drawing.Size(84, 20)
        Me.RadioButtonOneWay.TabIndex = 0
        Me.RadioButtonOneWay.TabStop = True
        Me.RadioButtonOneWay.Text = "One Way"
        Me.RadioButtonOneWay.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(293, 84)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(121, 16)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "No of Passengers: "
        '
        'TextBoxNOPassenger
        '
        Me.TextBoxNOPassenger.Location = New System.Drawing.Point(421, 84)
        Me.TextBoxNOPassenger.Name = "TextBoxNOPassenger"
        Me.TextBoxNOPassenger.Size = New System.Drawing.Size(100, 22)
        Me.TextBoxNOPassenger.TabIndex = 4
        '
        'LabelTotal
        '
        Me.LabelTotal.AutoSize = True
        Me.LabelTotal.Location = New System.Drawing.Point(293, 208)
        Me.LabelTotal.Name = "LabelTotal"
        Me.LabelTotal.Size = New System.Drawing.Size(78, 16)
        Me.LabelTotal.TabIndex = 5
        Me.LabelTotal.Text = "Total Price: "
        '
        'ButtonCalculate
        '
        Me.ButtonCalculate.Location = New System.Drawing.Point(371, 281)
        Me.ButtonCalculate.Name = "ButtonCalculate"
        Me.ButtonCalculate.Size = New System.Drawing.Size(75, 23)
        Me.ButtonCalculate.TabIndex = 6
        Me.ButtonCalculate.Text = "Calculate"
        Me.ButtonCalculate.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.ButtonCalculate)
        Me.Controls.Add(Me.LabelTotal)
        Me.Controls.Add(Me.TextBoxNOPassenger)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents RadioButtonSenaiKuc As RadioButton
    Friend WithEvents RadioButtonSenaiKul As RadioButton
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents RadioButtonTwoWay As RadioButton
    Friend WithEvents RadioButtonOneWay As RadioButton
    Friend WithEvents Label1 As Label
    Friend WithEvents TextBoxNOPassenger As TextBox
    Friend WithEvents LabelTotal As Label
    Friend WithEvents ButtonCalculate As Button
End Class
