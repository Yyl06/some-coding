<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form3
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
        Me.RegisterStudentListBox = New System.Windows.Forms.ListBox()
        Me.SelectedStudentListBox = New System.Windows.Forms.ListBox()
        Me.InsertNameButton = New System.Windows.Forms.Button()
        Me.SelectStudentButton = New System.Windows.Forms.Button()
        Me.RemoveButton = New System.Windows.Forms.Button()
        Me.SortButton = New System.Windows.Forms.Button()
        Me.InsertNameTextBox = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'RegisterStudentListBox
        '
        Me.RegisterStudentListBox.FormattingEnabled = True
        Me.RegisterStudentListBox.ItemHeight = 16
        Me.RegisterStudentListBox.Location = New System.Drawing.Point(92, 48)
        Me.RegisterStudentListBox.Name = "RegisterStudentListBox"
        Me.RegisterStudentListBox.Size = New System.Drawing.Size(120, 84)
        Me.RegisterStudentListBox.TabIndex = 0
        '
        'SelectedStudentListBox
        '
        Me.SelectedStudentListBox.FormattingEnabled = True
        Me.SelectedStudentListBox.ItemHeight = 16
        Me.SelectedStudentListBox.Location = New System.Drawing.Point(583, 48)
        Me.SelectedStudentListBox.Name = "SelectedStudentListBox"
        Me.SelectedStudentListBox.Size = New System.Drawing.Size(120, 84)
        Me.SelectedStudentListBox.TabIndex = 1
        '
        'InsertNameButton
        '
        Me.InsertNameButton.Location = New System.Drawing.Point(154, 229)
        Me.InsertNameButton.Name = "InsertNameButton"
        Me.InsertNameButton.Size = New System.Drawing.Size(75, 23)
        Me.InsertNameButton.TabIndex = 2
        Me.InsertNameButton.Text = "Insert"
        Me.InsertNameButton.UseVisualStyleBackColor = True
        '
        'SelectStudentButton
        '
        Me.SelectStudentButton.Location = New System.Drawing.Point(283, 229)
        Me.SelectStudentButton.Name = "SelectStudentButton"
        Me.SelectStudentButton.Size = New System.Drawing.Size(75, 23)
        Me.SelectStudentButton.TabIndex = 3
        Me.SelectStudentButton.Text = "Select"
        Me.SelectStudentButton.UseVisualStyleBackColor = True
        '
        'RemoveButton
        '
        Me.RemoveButton.Location = New System.Drawing.Point(410, 229)
        Me.RemoveButton.Name = "RemoveButton"
        Me.RemoveButton.Size = New System.Drawing.Size(75, 23)
        Me.RemoveButton.TabIndex = 4
        Me.RemoveButton.Text = "Remove"
        Me.RemoveButton.UseVisualStyleBackColor = True
        '
        'SortButton
        '
        Me.SortButton.Location = New System.Drawing.Point(526, 229)
        Me.SortButton.Name = "SortButton"
        Me.SortButton.Size = New System.Drawing.Size(75, 23)
        Me.SortButton.TabIndex = 5
        Me.SortButton.Text = "Sort"
        Me.SortButton.UseVisualStyleBackColor = True
        '
        'InsertNameTextBox
        '
        Me.InsertNameTextBox.Location = New System.Drawing.Point(355, 74)
        Me.InsertNameTextBox.Name = "InsertNameTextBox"
        Me.InsertNameTextBox.Size = New System.Drawing.Size(100, 22)
        Me.InsertNameTextBox.TabIndex = 6
        '
        'Form3
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.InsertNameTextBox)
        Me.Controls.Add(Me.SortButton)
        Me.Controls.Add(Me.RemoveButton)
        Me.Controls.Add(Me.SelectStudentButton)
        Me.Controls.Add(Me.InsertNameButton)
        Me.Controls.Add(Me.SelectedStudentListBox)
        Me.Controls.Add(Me.RegisterStudentListBox)
        Me.Name = "Form3"
        Me.Text = "Form3"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents RegisterStudentListBox As ListBox
    Friend WithEvents SelectedStudentListBox As ListBox
    Friend WithEvents InsertNameButton As Button
    Friend WithEvents SelectStudentButton As Button
    Friend WithEvents RemoveButton As Button
    Friend WithEvents SortButton As Button
    Friend WithEvents InsertNameTextBox As TextBox
End Class
