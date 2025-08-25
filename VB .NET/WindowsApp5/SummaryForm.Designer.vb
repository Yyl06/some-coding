<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SummaryForm
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
        Me.LabelCustomer = New System.Windows.Forms.Label()
        Me.LabelSales = New System.Windows.Forms.Label()
        Me.LabelAverageSales = New System.Windows.Forms.Label()
        Me.ShowCustomers = New System.Windows.Forms.Label()
        Me.ShowSales = New System.Windows.Forms.Label()
        Me.ShowAverage = New System.Windows.Forms.Label()
        Me.ButtonClose = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'LabelCustomer
        '
        Me.LabelCustomer.AutoSize = True
        Me.LabelCustomer.Location = New System.Drawing.Point(114, 76)
        Me.LabelCustomer.Name = "LabelCustomer"
        Me.LabelCustomer.Size = New System.Drawing.Size(111, 16)
        Me.LabelCustomer.TabIndex = 0
        Me.LabelCustomer.Text = "Total Customers: "
        '
        'LabelSales
        '
        Me.LabelSales.AutoSize = True
        Me.LabelSales.Location = New System.Drawing.Point(114, 108)
        Me.LabelSales.Name = "LabelSales"
        Me.LabelSales.Size = New System.Drawing.Size(82, 16)
        Me.LabelSales.TabIndex = 1
        Me.LabelSales.Text = "Total Sales: "
        '
        'LabelAverageSales
        '
        Me.LabelAverageSales.AutoSize = True
        Me.LabelAverageSales.Location = New System.Drawing.Point(114, 143)
        Me.LabelAverageSales.Name = "LabelAverageSales"
        Me.LabelAverageSales.Size = New System.Drawing.Size(103, 16)
        Me.LabelAverageSales.TabIndex = 2
        Me.LabelAverageSales.Text = "Average Sales: "
        '
        'ShowCustomers
        '
        Me.ShowCustomers.AutoSize = True
        Me.ShowCustomers.Location = New System.Drawing.Point(231, 76)
        Me.ShowCustomers.Name = "ShowCustomers"
        Me.ShowCustomers.Size = New System.Drawing.Size(15, 16)
        Me.ShowCustomers.TabIndex = 3
        Me.ShowCustomers.Text = "()"
        '
        'ShowSales
        '
        Me.ShowSales.AutoSize = True
        Me.ShowSales.Location = New System.Drawing.Point(202, 108)
        Me.ShowSales.Name = "ShowSales"
        Me.ShowSales.Size = New System.Drawing.Size(18, 16)
        Me.ShowSales.TabIndex = 4
        Me.ShowSales.Text = "() "
        '
        'ShowAverage
        '
        Me.ShowAverage.AutoSize = True
        Me.ShowAverage.Location = New System.Drawing.Point(223, 143)
        Me.ShowAverage.Name = "ShowAverage"
        Me.ShowAverage.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.ShowAverage.Size = New System.Drawing.Size(18, 16)
        Me.ShowAverage.TabIndex = 5
        Me.ShowAverage.Text = "() "
        '
        'ButtonClose
        '
        Me.ButtonClose.Location = New System.Drawing.Point(144, 199)
        Me.ButtonClose.Name = "ButtonClose"
        Me.ButtonClose.Size = New System.Drawing.Size(75, 23)
        Me.ButtonClose.TabIndex = 6
        Me.ButtonClose.Text = "Close"
        Me.ButtonClose.UseVisualStyleBackColor = True
        '
        'SummaryForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(383, 310)
        Me.Controls.Add(Me.ButtonClose)
        Me.Controls.Add(Me.ShowAverage)
        Me.Controls.Add(Me.ShowSales)
        Me.Controls.Add(Me.ShowCustomers)
        Me.Controls.Add(Me.LabelAverageSales)
        Me.Controls.Add(Me.LabelSales)
        Me.Controls.Add(Me.LabelCustomer)
        Me.Name = "SummaryForm"
        Me.Text = "Summary"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents LabelCustomer As Label
    Friend WithEvents LabelSales As Label
    Friend WithEvents LabelAverageSales As Label
    Friend WithEvents ShowCustomers As Label
    Friend WithEvents ShowSales As Label
    Friend WithEvents ShowAverage As Label
    Friend WithEvents ButtonClose As Button
End Class
